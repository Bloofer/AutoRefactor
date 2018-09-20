/*
 * Methods used for giving refactoring guides
 * These methods are used for simple analysis to get refactoring decisions
 * Implemented by jmyang <jmyang@ropas.snu.ac.kr>
 */

#include "treeutil.h"
using namespace std;

map<string,int> name2id;
map<int,string> id2name;

static const string mods[] = {
  "public", "protected", "private", "static", "abstract", "final", 
  "native", "synchronized", "transient", "volatile", "strictfp"
};
vector<string> Modifiers(mods, mods+sizeof(mods)/sizeof(mods[0]));

int yyparse();

extern Tree *root;

void id_init();

bool hasNodeId(vector<NodeData> &ndVec, int idx, int id){

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

void printNodeVector(vector<NodeData> &ndVec){

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

pair<string, string> parseArg(vector<string> &tokVec){

  string argT, argN;
  argN = tokVec.at(tokVec.size()-1);
  for(int i=0; i<tokVec.size()-1; i++){
    argT += tokVec.at(i);
    if(tokVec.at(i) == ",") argT += " ";
  }

  return pair<string, string>(argT, argN);

}

void clearFtype(FtnType &ftype){
  ftype.bopenLine = 0;
  ftype.ftnArgs.clear();
  ftype.ftnName = "";
  ftype.modifiers.clear();
  ftype.annotations.clear();
  ftype.lineNum = 0;
  ftype.returnType = "";
  ftype.exceptions.clear();
}

void parseFtype(vector<NodeData> &ndVec, FtnType &ftype){
  // NOTE : must pass ndVec of specific function

  clearFtype(ftype);

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
  // MODIFIERS | RETURN_TYPE | FTN_NAME ( ARG_TYPE ARG_NAME, ... ) [EXCEPTION_THROW] {

  vector<string> argTok;
  pair<string, string> argT;
  vector<string> tempArg;
  tdeli = ndeli = false;
  bool argOpen = false;
  bool argClose = false;
  int bnum = 0;

  for(int i=0; i<tokVec.size(); i++){
    if(tokVec.at(i) != "|" && !tdeli) ftype.modifiers.push_back(tokVec.at(i));
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
        argT = parseArg(tempArg);
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
        ftype.exceptions.push_back("Exception");
        return;
      }
    }
  }

}

bool isLvalueNode(vector<NodeData> &ndVec, int idx){
// input : node vector for parsed ftn tree & index for specific node number

  return hasNodeId(ndVec, idx, 65) || hasNodeId(ndVec, idx, 123);
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

vector< pair<NodeData, int> > findNodeByLabel(vector<NodeData> &ndVec, string label){

  vector< pair<NodeData, int> > outVec;

  for(int i=0; i<ndVec.size(); i++){
    if(ndVec.at(i).label == label) outVec.push_back(pair<NodeData, int>(ndVec.at(i), i));
  }

  return outVec;

}

pair<int, int> findBiggestBracketInScope(vector<NodeData> &ndVec, pair<int, int> &scope){
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

vector< pair<string, string> > findPrmtvLocVarInScope(vector<NodeData> &ndVec, pair<int, int> &scope){

  //cout << scope.first << " " << scope.second << endl;

  // find vector scope indices
  int abv = 0;
  bool abvChk = false;
  int blw;
  for(int i=0; i<ndVec.size(); i++){
    if(!abvChk && ndVec.at(i).isTerminal && ndVec.at(i).lineNo < scope.first){
      abv = i + 1;
    } else if(!abvChk && ndVec.at(i).isTerminal && ndVec.at(i).lineNo >= scope.first){
      abvChk = true;
    } 
  }

  blw = ndVec.size(); // below scope is to the end of the function

  //cout << "scope : " << ndVec.at(abv-1).lineNo << " " << ndVec.at(blw).lineNo << endl;

  if(!abvChk) cerr << "Error : Se Loc var scope not found." << endl;

  vector< pair<string, string> > locVars;
  bool tfound = false;
  bool nfound = false;
  bool isPrmtv = false;
  int bopen = 0;
  string varType, varName;

  //printNodeVector(ndVec);

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
    } 
  }

  return locVars;

}

vector< pair<string, string> > findLocVarInScope(vector<NodeData> &ndVec, pair<int, int> &scope){

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

  //printNodeVector(ndVec);

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

vector< pair<NodeData, int> > findNodeByLine(vector<NodeData> &ndVec, int lineNum){

  vector< pair<NodeData, int> > outVec;

  for(int i=0; i<ndVec.size(); i++){
    if(ndVec.at(i).lineNo == lineNum) outVec.push_back(pair<NodeData, int>(ndVec.at(i), i));
  }

  return outVec;

}

int lineParenthesisChk(vector<NodeData> &ndVec, int lineNum){

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

vector<NodeData> getSubNdVec(vector<NodeData> &ndVec, int frt, int bck){

  vector<NodeData> subNdVec;
  for(int i=0; i<ndVec.size(); i++){
    if(i>=frt && i<=bck) subNdVec.push_back(ndVec.at(i));
  }
  return subNdVec;

}

vector<string> getAnnotListFromModNdVec(vector<NodeData> &ndVec, int annotCnt){

  vector<string> annotList;
  vector<string> tnodeVec = getTnodeLabelInNdVec(ndVec);
  string tmpAnnot = "";
  bool annotChk = false;

  for(int i=0; i<tnodeVec.size(); i++){
    if(tnodeVec.at(i) == "@" && i != 0) {
      annotList.push_back(tmpAnnot);
      tmpAnnot = "";
    } else if(tnodeVec.at(i) != "@"){
      tmpAnnot += tnodeVec.at(i);
    }
  }
  annotList.push_back(tmpAnnot);

  if(annotList.size() == annotCnt){
    return annotList;
  } else {
    cerr << "Error : ftn annotation parsing error. @ getAnnotListFromModNdVec()" << endl;
    return annotList;
  }

}

vector< pair<string, string> > getArgListFromArgNdVec(vector<NodeData> &ndVec, int argCnt){
  // note : input should be multiple arg ndVec

  int frt = 0;
  int bck = 0;
  int found = 0;
  vector< pair<string, string> > argList;
  vector<NodeData> tmpNdVec;

  for(int i=0; i<ndVec.size(); i++){

    if(found == argCnt - 1){
      tmpNdVec = getSubNdVec(ndVec, frt, ndVec.size()-1);
      vector<string> labels = getTnodeLabelInNdVec(tmpNdVec);
      string argT = "";
      for(int i=0; i<labels.size()-1; i++){
        argT += labels.at(i);
      }
      string argN = labels.back();
      argList.push_back(pair<string, string>(argT, argN));
      frt = bck+3;
      found++;
      tmpNdVec.clear();
    } else if(i < ndVec.size() - 1 && ndVec.at(i).label == "," && ndVec.at(i+1).nodeId == 178){
      // fetching arg scope
      if(i > 0){
        // push back args before last element
        bck = i-1;
        tmpNdVec = getSubNdVec(ndVec, frt, bck);
        vector<string> labels = getTnodeLabelInNdVec(tmpNdVec);
        string argT = "";
        for(int i=0; i<labels.size()-1; i++){
          argT += labels.at(i);
        }
        string argN = labels.back();
        argList.push_back(pair<string, string>(argT, argN));
        frt = bck+3;
        found++;
        tmpNdVec.clear();
      }
    }

  }

  if(found == argCnt){
    return argList;
  } else {
    cerr << "Error : ftn arg parsing error. @ getArgListFromArgNdVec()" << endl;
    return argList;
  }

}

void parseFtnType(string &fileName, string &ftnName, FtnType &ftype, vector<NodeData> &ndVec){
  
  id_init();

  ParseTree* pt = parseFile(fileName.c_str());
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }
  
  stringstream fss;
  pt->getRoot()->getFtnSubtree(fss, ftnName);

  vector<NodeData> fNdVec;
  ss2NodeVec(fNdVec, fss);
  int ftnDeclLine = -1;
  int ftnBopenLine = -1;
  bool fnd = false;

  // find bracket opener offset
  for(int i=0; i<fNdVec.size(); i++){
    if(!fnd && i<fNdVec.size()-3 && fNdVec.at(i).nodeId == 187 && fNdVec.at(i+1).nodeId == 39) {
      ftnDeclLine = fNdVec.at(i+2).lineNo;
    } else if(!fnd && i<fNdVec.size()-4 && fNdVec.at(i).nodeId == 171 && fNdVec.at(i+1).nodeId == 98 && fNdVec.at(i+2).nodeId == 7) {
      ftnBopenLine = fNdVec.at(i+3).lineNo;
      fnd = true;
      break;
    }
  }
  if(ftnDeclLine == -1 || ftnBopenLine == -1){
    cerr << "Error : parsing error during ftn decl line & bracket opener line parse @ parseFtnType" << endl;
    return;
  }
  ftype.bopenLine = ftnBopenLine - ftnDeclLine;

  stringstream ss;
  pt->getRoot()->getFtnPdata(ss, ftnName);

  vector<NodeData> tmpNdVec;
  string modsSs, rtypeSs, fnameSs, argsSs, ExcsSs, line;
  int lineCnt = 1;
  bool fstDeli = false;
  bool sndDeli = false;
  bool argParsed = false;
  bool exctParsed = false;

  while(getline(ss, line)){
    stringstream tmpSs;
    if(lineCnt == 1){
      // 1. parse annotations & modifiers
      tmpSs << line;
      ss2NodeVec(tmpNdVec, tmpSs);

      // 1-1. split annot list and fetch annots  
      int annotCnt = 0;
      int annotDeli = 0;
      bool found = false;
      for(int i=0; i<tmpNdVec.size(); i++){
        if (tmpNdVec.at(i).nodeId == 175) annotCnt++;
        if (!found && i < tmpNdVec.size() - 1 && tmpNdVec.at(i).nodeId == 147 && tmpNdVec.at(i+1).nodeId != 175) {
          annotDeli = i;
          found = true;
        }
      }
    
      vector<NodeData> annotNdVec = getSubNdVec(tmpNdVec, 0, annotDeli-1);
      vector<string> annotList = getAnnotListFromModNdVec(annotNdVec, annotCnt);
      ftype.annotations.insert(ftype.annotations.end(), annotList.begin(), annotList.end());

      // 1-2. parse modifiers
      vector<NodeData> modNdVec = getSubNdVec(tmpNdVec, annotDeli, tmpNdVec.size());
      vector<string> modList = getTnodeLabelInNdVec(modNdVec);
      ftype.modifiers.insert(ftype.modifiers.end(), modList.begin(), modList.end());

      tmpNdVec.clear();
    } else if(lineCnt == 2){
      // 2. parse return type
      tmpSs << line;
      ss2NodeVec(tmpNdVec, tmpSs);
      vector<string> rType = getTnodeLabelInNdVec(tmpNdVec);
      string rTypeStr = "";
      if(rType.size() == 0){
        cerr << "Error : return type not parsed @ ftn : " << ftnName << endl;
        return;
      } else{
        for(int i=0; i<rType.size(); i++){
          rTypeStr += rType.at(i);
        }
        ftype.returnType = rTypeStr;
      }
      tmpNdVec.clear();
    } else if(lineCnt == 3){
      // 3. parse ftn name
      tmpSs << line;
      ss2NodeVec(tmpNdVec, tmpSs);
      vector<string> fname = getTnodeLabelInNdVec(tmpNdVec);
      if(fname.size() != 1){
        cerr << "Error : ftn name not parsed @ ftn : " << ftnName << endl;
        return;
      } else{
        ftype.ftnName = fname.front();
      }
      tmpSs.str("");
      tmpNdVec.clear();
    } else if(lineCnt == 4){
      // 4. delimeter line. this line should be compose of '|'. else return error.
      if(line == "|") fstDeli = true;
      else {
        cerr << "Error : arg not parsed #1 @ ftn : " << ftnName << endl;
        return;
      }
    } else if(lineCnt > 4 && fstDeli && !argParsed && !sndDeli && !exctParsed) {
      // 5. parse args and if accept delimeter '|', then parse exceptions
      if(line == "|"){
        // if there exists no ftn args, pass below process
        argParsed = true;
        sndDeli = true;
        tmpSs.str("");
      } else {
        tmpSs << line;
        argParsed = true;
        ss2NodeVec(tmpNdVec, tmpSs);
        // 1. check nt node which has id 178(formal_param) to get arg num
        int argCnt = 0;
        for(int i=0; i<tmpNdVec.size(); i++){
          if(tmpNdVec.at(i).nodeId == 178) argCnt++;
        }

        if (argCnt == 0){
          // if no args found.
          tmpSs.str("");
          tmpNdVec.clear();  
        } else if (argCnt == 1){
          // if one or more args found, parse arg one by one
          vector<string> labels = getTnodeLabelInNdVec(tmpNdVec);
          string argT = "";
          for(int i=0; i<labels.size()-1; i++){
            argT += labels.at(i);
          }
          string argN = labels.back();
          ftype.ftnArgs.push_back(pair<string, string>(argT, argN));
          tmpSs.str("");
          tmpNdVec.clear();
        } else {
          // get arg list from arg vec ()
          // 1. split tnode list
          // 2. push_back args from tnode list
          vector< pair<string, string> > argList = getArgListFromArgNdVec(tmpNdVec, argCnt);
          //ftype.ftnArgs.insert(ftype.ftnArgs.end(), argList.begin(), argList.end());
          ftype.ftnArgs = argList;
          tmpSs.str("");
          tmpNdVec.clear();
        }
      }
    } else if(lineCnt > 4 && fstDeli && argParsed && !sndDeli && !exctParsed) {
      if(line == "|") sndDeli = true;
      else {
        cerr << "Error : arg not parsed #1 @ ftn : " << ftnName << endl;
        return;
      }
    } else if(lineCnt > 4 && fstDeli && argParsed && sndDeli && !exctParsed) {
      tmpSs << line;
      exctParsed = true;
      // TODO: only 1 exception is parsed. need to expand to accept multi exception throws.
      ss2NodeVec(tmpNdVec, tmpSs);
      vector<string> labels = getTnodeLabelInNdVec(tmpNdVec);
      ftype.exceptions.push_back(labels.back());
      tmpNdVec.clear();
      tmpSs.str("");
    } else if(lineCnt > 4 && fstDeli && argParsed && sndDeli && exctParsed) {
      cerr << "Error : something left to parse after exct? @ ftn : " << ftnName << endl; 
      return;
    }
    
    lineCnt++;  
  }


  //ss2NodeVec(ndVec, ss);

}

vector<string> getTnodeLabelInNdVec(vector<NodeData> &ndVec){

  if(ndVec.empty()) cerr << "Error : ndVec is empty. tnode cannot be found. @ getTnodeLabelInNdVec()" << endl;
  vector<string> tnodeLabelVec;
  for(int i=0; i<ndVec.size(); i++){
    if (ndVec.at(i).isTerminal) tnodeLabelVec.push_back(ndVec.at(i).label);
  }
  return tnodeLabelVec;

}

NodeData findFstTnodeInNdvec(vector<NodeData> &ndVec){

  bool found = false;
  NodeData fstNode;
  if(ndVec.size() == 0) {
    cerr << "Error : ndVec is empty. cannot find first node." << endl;
    return fstNode;
  }

  for(int i=0; i<ndVec.size(); i++){
    if(ndVec.at(i).isTerminal) {
      found = true;
      fstNode = ndVec.at(i);
      break;
    }
  }

  if(found) return fstNode;
  else {
    cerr << "Error : cannot find first node." << endl;
    return fstNode;
  }

}

NodeData findLstTnodeInNdvec(vector<NodeData> &ndVec){

  bool found = false;
  NodeData lstNode;
  if(ndVec.size() == 0) {
    cerr << "Error : ndVec is empty. cannot find last node." << endl;
    return lstNode;
  }

  for(int i=ndVec.size()-1; i>=0; i--){
    if(ndVec.at(i).isTerminal) {
      found = true;
      lstNode = ndVec.at(i);
      break;
    }
  }

  if(found) return lstNode;
  else {
    cerr << "Error : Cannot find last node." << endl;
    return lstNode;
  }

}

bool isEmptyNodeData(NodeData &nd){

  return (nd.depth == 0) && (nd.isTerminal == 0) && (nd.label == "") && (nd.lineNo == 0) && (nd.nodeId == 0);

}

void getAllFtnData(string &fileName, vector<FtnData> &fdVec){
  
  id_init();

  ParseTree* pt = parseFile(fileName.c_str());
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }
  
  // 1. 모든 함수 이름 가져오기
  stringstream ss;
  pt->getRoot()->getAllFtnName(ss);

  string fname;
  FtnData fdata;
  vector<NodeData> ndVec;
  while(ss >> fname){
    // 2. 가져온 함수 이름으로 getFtnSubtree() 호출하고
    stringstream fss;
    pt->getRoot()->getFtnSubtree(fss, fname);
    ss2NodeVec(ndVec, fss);
    NodeData fstNode = findFstTnodeInNdvec(ndVec);
    NodeData lstNode = findLstTnodeInNdvec(ndVec);

    // 3. 가져온 ndVec에서 앞 뒤 노드 from, to에 이름과 함께 삽입.
    if(isEmptyNodeData(fstNode) || isEmptyNodeData(lstNode)) {
      cerr << "Error: parsed ftn subtree cannot find first | last node on ftn : " << fname << endl;
      return;
    }

    fdata.from = fstNode.lineNo;
    fdata.to = lstNode.lineNo;
    fdata.ftnName = fname;
    fdVec.push_back(fdata);
    fdata.from = fdata.to = 0;
    fdata.ftnName = "";
    ndVec.clear();
  }  
  
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

string getClassModifier(string &file_name, string &class_type){

  ParseTree* pt = parseFile(file_name.c_str());
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << file_name << endl;
    return "";
  }

  string find = pt->getRoot()->findCnode("class", class_type);

}