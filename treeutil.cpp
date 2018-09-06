/*
 * Methods used for giving refactoring guides
 * These methods are used for simple analysis to get refactoring decisions
 * Implemented by jmyang <jmyang@ropas.snu.ac.kr>
 */

#include "include/ptree.h"
#include <sys/types.h>
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <ptree.h>
#include <map>
#include <list>
#include <string>
#include <string.h>
#include <token-tree-map.h>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <functional>
#include <iterator>
using namespace std;

typedef struct _ClassHierarchy {
  string file_name;
  string class_name;
  string parent_class_name;
  string parent_interface_name;
} ClassHierarchy;

// maybe needed to be expanded?
typedef struct _CallGraph {
//  string caller_path; // caller's full path   ex) fasoo.eprint.f1.blah....
  string caller_cname;// caller's class name
  string caller_fname;// caller's function name
//  string callee_path; // callee's full path
  string callee_cname;// callee's class name
//  string callee_fname;// callee's function name
} CallGraph;

// type definition for refactor guide
// EM - Extract Method, PM - Pull-up Method, ES - Extract Superclass
// ES1 refers refactoring point which has different parent class & ES2 refers to refactoring point whose parent class is API class
typedef enum {
  EM, 
  PM, 
  ES1, 
  ES2, 
  DONTKNOW
} refactor_pattern_t;

map<string,int> name2id;
map<int,string> id2name;

int yyparse();

extern Tree *root;

void id_init();

typedef struct{
  int nodeId;
  bool isTerminal;
  string label; // empty if non-terminal
  int lineNo;   // empty if non-terminal
  int depth;    // depth of tree. same if siblings
}NodeData;

typedef struct{
    vector<string> keywords;
    string returnType;
    vector< pair<string, string> > ftnArgs; // pair for (arg_type, arg_name). vector for multiple args
    string ftnName;
    bool thrwExtn;
    int lineNum;
    int bopenLine;
}FtnType;

bool has_node_id(vector<NodeData> &ndVec, int idx, int id){

  // 1. get gap between index
  int back = idx-1;
  int front = back;
  while(front >= 0){
    if(!ndVec.at(front).isTerminal) front--;
    else break;
  }

  // 2. check if gap has id. returns true if have had
  bool has = false;
  for(int i=front; i<=back; i++) {
    //cout << ndVec.at(i).depth << endl;
    has |= (ndVec.at(i).nodeId==id);
  }

  return has;

}

void print_node_vector(vector<NodeData> &ndVec){

  for(int i=0; i<ndVec.size(); i++){

    if(ndVec.at(i).isTerminal) {
      cout << "T [ nodeID : " << ' ' << " \tlabel : " << ndVec.at(i).label 
           << "\tlineNum : " << ndVec.at(i).lineNo << "\tdepth : " << ndVec.at(i).depth << " ]\n";
    } else {
      cout << "NT[ nodeID : " << ndVec.at(i).nodeId << " \tlabel : " << ' '
           << "\tlineNum : " << ' ' << "\tdepth : " << ndVec.at(i).depth << " ]\n";
    }

  }

}

pair<string, string> parse_arg(vector<string> &tokVec){

  string argT, argN;
  argN = tokVec.at(tokVec.size()-1);
  for(int i=0; i<tokVec.size()-1; i++){
    argT += tokVec.at(i);
    if(tokVec.at(i) == ",") argT += " ";
  }

  return pair<string, string>(argT, argN);

}

void parse_ftype(vector<NodeData> &ndVec, FtnType &ftype){
  // NOTE : must pass ndVec of specific function

  bool tdeli = false;
  bool ndeli = false;
  int fstL;

  vector<string> tokVec;

  for(int i=0; i<ndVec.size()-2; i++){
    if(ndVec.at(i).isTerminal) { 
      tokVec.push_back(ndVec.at(i).label);
    }
    if(ndVec.at(i).nodeId == 123 && !tdeli) {
      tokVec.push_back("|");
      tdeli = true;
    }
    if(ndVec.at(i).nodeId == 187 && !ndeli) {
      tokVec.push_back("|");
      fstL = ndVec.at(i+2).lineNo;
      ndeli = true;
    }
    if(ndVec.at(i).isTerminal && ndVec.at(i).label=="{") {
      ftype.bopenLine = ndVec.at(i).lineNo - fstL;
      break;
    }
  }

  // parsed with given sequence
  // KEYWORDS | RETURN_TYPE | FTN_NAME ( ARG_TYPE ARG_NAME, ... ) [EXCEPTION_THROW] {

  vector<string> argTok;
  pair<string, string> argT;
  vector<string> tempArg;
  tdeli = ndeli = false;
  bool argOpen = false;
  bool argClose = false;
  int bnum = 0;

  for(int i=0; i<tokVec.size(); i++){
    if(tokVec.at(i) != "|" && !tdeli) ftype.keywords.push_back(tokVec.at(i));
    else if(tokVec.at(i) == "|" && !tdeli) tdeli = true;
    else if(tdeli && tokVec.at(i) != "|" && !ndeli) ftype.returnType += tokVec.at(i);
    else if(tdeli && tokVec.at(i) == "|" && !ndeli) ndeli = true;
    else if(tdeli && ndeli && tokVec.at(i) != "(" && !argOpen) ftype.ftnName = tokVec.at(i);
    else if(tdeli && ndeli && tokVec.at(i) == "(" && !argOpen) {
      argOpen = true;
      if(i<tokVec.size()-1 && tokVec.at(i)==")") argClose = true;
    }
    else if(tdeli && ndeli && argOpen && !argClose) {
      if(tokVec.at(i) == "<") bnum++;
      if(tokVec.at(i) == ">") bnum--;
      if(bnum == 0 && ( tokVec.at(i) == "," || tokVec.at(i) == ")" ) ) {
        argT = parse_arg(tempArg);
        ftype.ftnArgs.push_back(argT);
        argT.first = argT.second = "";
        tempArg.clear();
        if(tokVec.at(i) == ")") argClose = true;
      } else {
        tempArg.push_back(tokVec.at(i));
      }
    }
    else if(tdeli && ndeli && argOpen && argClose && tokVec.at(i)!="{") { 
      if(i<tokVec.size()-1 && tokVec.at(i) == "throws" && tokVec.at(i+1) == "Exception") {
        ftype.thrwExtn = true;
        return;
      }
    }
  }

}

bool is_lvalue_node(vector<NodeData> &ndVec, int idx){
// input : node vector for parsed ftn tree & index for specific node number

  return has_node_id(ndVec, idx, 65) || has_node_id(ndVec, idx, 123);
  // 65 : type,  123 : var_decl

}

// method for finding class label. works only on fetching class names
void fetchClassHierarchy(string &file_name, string &classname, string &parent_classname, string &parent_intername){

  ParseTree* pt = parseFile(file_name.c_str());
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << file_name << endl;
    return;
  }

  // method for finding class label. works only on fetching class names
  string find = pt->getRoot()->findNode("class", classname, parent_classname, parent_intername);

}

void getPtree(string &fileName, stringstream &ss){

  ParseTree* pt = parseFile(fileName.c_str());
  
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }

  string fname = "f";
  pt->getRoot()->getFtnSubtree(ss, fname);

}

void dumpPtree(string &fileName){

  id_init();

  ParseTree* pt = parseFile(fileName.c_str());
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }

  pt->outputParseTree2Dot(fileName.c_str(), false);
  
}

int str2int(const char *s)
{
    int i;
    i = 0;
    while(*s >= '0' && *s <= '9')
    {
        i = i * 10 + (*s - '0');
        s++;
    }
    return i;
}

vector< pair<NodeData, int> > find_node_by_label(vector<NodeData> &ndVec, string label){

  vector< pair<NodeData, int> > outVec;

  for(int i=0; i<ndVec.size(); i++){
    if(ndVec.at(i).label == label) outVec.push_back(pair<NodeData, int>(ndVec.at(i), i));
  }

  return outVec;

}

pair<int, int> find_biggest_bracket_in_scope(vector<NodeData> &ndVec, pair<int, int> &scope){
  // returns vector line pair of the biggest bracket

  // 구간 내 터미널 라인 번호 터미널 노드 먼저 짚기
  int from, to;
  from = to = 0;
  for(int i=0; i<ndVec.size(); i++){
    if(ndVec.at(i).lineNo >= scope.first) {
      from = i;
      break;
    }
  }
  for(int i=ndVec.size()-1; i>=0; i--){
    if(ndVec.at(i).lineNo <= scope.second) {
      to = i;
      break;
    }
  }
  if(from == 0 && to == 0) return pair<int, int>(0, 0); // error case

  vector<int> stmtLoc; // vector for for/if/if-else statement counter
  for(int i=from; i<=to; i++){
    if (ndVec.at(i).nodeId == 22 || ndVec.at(i).nodeId == 99 || ndVec.at(i).nodeId == 107) {
      stmtLoc.push_back(i);
    }
  }

  //cout << "Number of bracket statements : " << stmtLoc.size() << endl;

  vector< pair<int, int> > stmtScopeVec; // vector for for/if/if-else statement found in the given scope

  for(int i=0; i<stmtLoc.size(); i++){

    int popenLine, pcloseLine;
    int popen, pclose;
    popen = pclose = 0;
    bool found = false;
    // for loop이나 if 찾아서 (앞쪽부터) popen pclose 짝 맞는 가장 큰 bracket 찾고 반환
    for(int j=stmtLoc.at(i); j<=to; j++){
      if (ndVec.at(j).label == "{" && !found) { 
        popen++;
        found = true;
        popenLine = ndVec.at(j).lineNo;
      } else if (ndVec.at(j).label == "{") {
        popen++;
      } else if (ndVec.at(j).label == "}") {
        pclose++;
        if(popen == pclose) {
          pcloseLine = ndVec.at(j).lineNo;
          stmtScopeVec.push_back(pair<int, int>(popenLine, pcloseLine));
          break;
        }
      }
    }

  }

  // find biggest bracket pair
  int bgstVal = 0;
  int bgstIdx;
  for(int i=0; i<stmtScopeVec.size(); i++){
    if((stmtScopeVec.at(i).second - stmtScopeVec.at(i).first) > bgstVal) {
      bgstVal = (stmtScopeVec.at(i).second - stmtScopeVec.at(i).first);
      bgstIdx = i;
    }
  }
  
  return stmtScopeVec.at(bgstIdx);

}

vector< pair<string, string> > find_loc_var_in_scope(vector<NodeData> &ndVec, pair<int, int> &scope){

  //cout << scope.first << " " << scope.second << endl;

  // find vector scope indices
  int abv = 0;
  bool abvChk = false;
  int blw = 0;
  bool blwChk = false;
  for(int i=0; i<ndVec.size(); i++){
    if(!abvChk && ndVec.at(i).isTerminal && ndVec.at(i).lineNo < scope.first){
      abv = i + 1;
    } else if(!abvChk && ndVec.at(i).isTerminal && ndVec.at(i).lineNo >= scope.first){
      abvChk = true;
    } else if(!blwChk && ndVec.at(i).isTerminal && ndVec.at(i).lineNo <= scope.second){
      blw = i;
    } else if(!blwChk && ndVec.at(i).isTerminal && ndVec.at(i).lineNo > scope.second){
      blwChk = true;
    }
  }

  //cout << "scope : " << ndVec.at(abv-1).lineNo << " " << ndVec.at(blw).lineNo << endl;

  if(!abvChk || !blwChk) cerr << "Error : Loc var scope not found." << endl;

  vector< pair<string, string> > locVars;
  bool tfound = false;
  bool nfound = false;
  bool isPrmtv = false;
  int bopen = 0;
  string varType, varName;

  //print_node_vector(ndVec);

  // find local vars
  for(int i=abv; i<blw-3; i++){
    if(ndVec.at(i).nodeId == 23 && ndVec.at(i+1).nodeId == 145 && ndVec.at(i+2).nodeId == 123 && !tfound){
      if(ndVec.at(i+3).nodeId == 117){
        // if type is primitive type
        tfound = isPrmtv = true;
        nfound = false;
      } else {
        tfound = true;
        nfound = false;
      }
    } else if (tfound && isPrmtv && !nfound){
      if(ndVec.at(i).isTerminal) { 
        varType = ndVec.at(i).label;
        //cout << varType;
        nfound = true;
        if(ndVec.at(i+1).nodeId == 4 && ndVec.at(i+2).nodeId == 65 && ndVec.at(i+3).nodeId == 37 && ndVec.at(i+4).nodeId == 39){
          if(ndVec.at(i+5).isTerminal) {
            varName = ndVec.at(i+5).label;
            //cout << varName;
            locVars.push_back(pair<string, string>(varType, varName));
            tfound = false;
          }
        }
      }
    } else if (tfound && !isPrmtv && !nfound){
      if(ndVec.at(i).isTerminal) { 
        varType += ndVec.at(i).label;
        if(ndVec.at(i+1).nodeId == 4 && ndVec.at(i+2).nodeId == 65 && ndVec.at(i+3).nodeId == 37 && ndVec.at(i+4).nodeId == 39){
          if(ndVec.at(i+5).isTerminal) {
            varName = ndVec.at(i+5).label;
            locVars.push_back(pair<string, string>(varType, varName));
            nfound = true;
            tfound = false;
          }
        }
      }
    }
  }

  return locVars;

}

vector< pair<NodeData, int> > find_node_by_line(vector<NodeData> &ndVec, int lineNum){

  vector< pair<NodeData, int> > outVec;

  for(int i=0; i<ndVec.size(); i++){
    if(ndVec.at(i).lineNo == lineNum) outVec.push_back(pair<NodeData, int>(ndVec.at(i), i));
  }

  return outVec;

}

int line_parenthesis_check(vector<NodeData> &ndVec, int lineNum){

  // checks if specific line has pair of parenthesis
  // will be used for line by line patching
  
  vector<NodeData> lineVec;

  for(int i=0; i<ndVec.size(); i++){
    if(ndVec.at(i).lineNo == lineNum) lineVec.push_back(ndVec.at(i));
  }

  int popen = 0;
  int pclose = 0;

  for(int i=0; i<lineVec.size(); i++){
    if(lineVec.at(i).label == "(") popen++;
    if(lineVec.at(i).label == ")") pclose++;
  }

  // output
  // - (negative) : need to include lineNum - 1 line to diff line
  // 0 : pair of parenthesis in one line.
  // + (positive) : need to include lineNum + 1 line to diff line

  vector<NodeData> lineVecNext;

  if (popen > pclose) {
    for(int i=0; i<ndVec.size(); i++){
      if(ndVec.at(i).lineNo == lineNum+1) lineVecNext.push_back(ndVec.at(i));
    }
    for(int i=0; i<lineVecNext.size(); i++){
      if(lineVecNext.at(i).label == "(") popen++;
      if(lineVecNext.at(i).label == ")") pclose++;
    }
    if (popen == pclose) return 1;
    else return 0;
  }
  else if (popen < pclose) {
    for(int i=0; i<ndVec.size(); i++){
      if(ndVec.at(i).lineNo == lineNum-1) lineVecNext.push_back(ndVec.at(i));
    }
    for(int i=0; i<lineVecNext.size(); i++){
      if(lineVecNext.at(i).label == "(") popen++;
      if(lineVecNext.at(i).label == ")") pclose++;
    }
    if (popen == pclose) return -1;
    else return 0;
  }
  else return 0;

}

void ss2NodeVec(vector<NodeData> &ndVec, stringstream &ss){

  string tok;
  int treeDepth = 0;

  while(ss >> tok){
    
    if (tok.at(0) == '[') {
      // if token is right tree parenthesis, increase depth
      treeDepth++;
    } else if (tok.at(0) == ']') {
      // if token is left tree parenthesis, decrease depth
      treeDepth--;
    } else if (tok.at(0) >= '0' && tok.at(0) <= '9') {
      // Non-terminal Node
      // if token is nodeID, create node object and push to vector
      NodeData ntNode;
      ntNode.nodeId = str2int(tok.c_str());
      ntNode.isTerminal = false;
      ntNode.label = ""; // leave it empty b.c. this data is not used for non-terminal node
      ntNode.lineNo = 0; // leave it zero b.c. this data is not used for non-terminal node
      ntNode.depth = treeDepth;
      ndVec.push_back(ntNode);
    } else if (tok.at(0) == '<') {
      // Terminal Node
      // if token is label, create node object and push to vector
      string tok1 = tok;

      assert(tok.size() >= 2);
      if (tok.substr(0,2) == "<\"") {
        if (tok.substr(tok.size()-2) != "\">") {
          ss >> tok;
          tok1 += (" " + tok);
          while(tok.size()<2 || tok.substr(tok.size()-2) != "\">") {
            ss >> tok;
            tok1 += (" " + tok);
          }
        }
      }
      string tok2;
      ss >> tok2; // parse second token to fetch line number

      //cout << tok1 << " ";

      NodeData tNode;
      tNode.nodeId = -1; // leave it negative one b.c. this data is not used for terminal node
      tNode.isTerminal = true;
      //assert(tok1.size() > 2);
      tNode.label = tok1.substr(1, tok1.size()-2);
      //assert(tok2.size() > 2);
      tNode.lineNo = str2int(tok2.substr(1).c_str());
      tNode.depth = treeDepth;
      ndVec.push_back(tNode);
    } else {
      // return error if found exceptional token in ss
      cerr << "Error : Abnormal token found in the string stream. Token : " << tok << endl;
      return;
    }

  }

}

void getFtnSubtree(string &fileName, string &ftnName, vector<NodeData> &ndVec){
  
  id_init();

  ParseTree* pt = parseFile(fileName.c_str());
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }
  
  stringstream ss;
  pt->getRoot()->getFtnSubtree(ss, ftnName);

  ss2NodeVec(ndVec, ss);

}

void getPtreeVec(string &fileName, vector<NodeData> &ndVec){
  
  id_init();

  ParseTree* pt = parseFile(fileName.c_str());
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }
  
  stringstream ss;
  pt->getRoot()->print2ss(ss);

  ss2NodeVec(ndVec, ss);

}

void printss(string &fileName){
  
  id_init();

  ParseTree* pt = parseFile(fileName.c_str());
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }
  
  stringstream ss;
  pt->getRoot()->print2ss(ss);

  cout << ss.str() << endl;

}

void print2ssFtnSubtree(string &fileName, string &ftnName){
  
  id_init();

  ParseTree* pt = parseFile(fileName.c_str());
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }
  
  stringstream ss;
  pt->getRoot()->getFtnSubtree(ss, ftnName);

  cout << ss.str() << endl;

}

string getClassKeyword(string &file_name, string &class_type){

  ParseTree* pt = parseFile(file_name.c_str());
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << file_name << endl;
    return "";
  }

  string find = pt->getRoot()->findCnode("class", class_type);

}