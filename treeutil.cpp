/*
 * YACC 파서에서 만들어낸 AST를 분석/이용하는 모듈
 * 트리/노드벡터 관련 함수들 구현
 * Implemented by jmyang <jmyang@ropas.snu.ac.kr>
 */

#include "treeutil.h"
using namespace std;

map<string,int> name2id;
map<int,string> id2name;

int yyparse();
extern Tree *root;
void id_init();





/*
 * ====================================================
 * =========== COMMUNAL FUNCTIONS FOR ALL =============
 * ====================================================
 */

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

// method for finding class label. works only on fetching class names
void fetchClassHierarchy(string &file_name, string &classname, string &parent_classname, string &parent_intername){

  ParseTree* pt = parseFile(file_name.c_str());
  if ( pt==NULL ) {
    cout << "Error: no parse tree created for file: " << file_name << endl;
    return;
  }

  // method for finding class label. works only on fetching class names
  string find = pt->getRoot()->findNode("class", classname, parent_classname, parent_intername);

}

void fetchClassName(string &file_name, string &classname){

  // parse .java file and get class or interface name

  ParseTree* pt = parseFile(file_name.c_str());
  if ( pt==NULL ) {
    cout << "Error: no parse tree created for file: " << file_name << endl;
    return;
  }

  // method for finding class label. works only on fetching class names
  string find = pt->getRoot()->getClassName(classname);

}

vector< pair<NodeData, int> > findNodeByLabel(vector<NodeData> &ndVec, string label){

  vector< pair<NodeData, int> > outVec;

  for(int i=0; i<ndVec.size(); i++){
    if(ndVec.at(i).label == label) outVec.push_back(pair<NodeData, int>(ndVec.at(i), i));
  }

  return outVec;

}

vector< pair<NodeData, int> > findNodeByLine(vector<NodeData> &ndVec, int lineNum){

  vector< pair<NodeData, int> > outVec;

  for(int i=0; i<ndVec.size(); i++){
    if(ndVec.at(i).lineNo == lineNum) outVec.push_back(pair<NodeData, int>(ndVec.at(i), i));
  }

  return outVec;

}

vector<NodeData> findNodeByLineWithNt(vector<NodeData> &ndVec, int lineNum){

  vector<NodeData> outVec;
  int frt, bck;
  bool frtFnd = false;
  bool bckFnd = false;

  for(int i=0; i<ndVec.size(); i++){
    if (ndVec.at(i).isTerminal && ndVec.at(i).lineNo == lineNum) {
      frtFnd = true;
      bck = i;
      bckFnd = true;
    } else if (!frtFnd && ndVec.at(i).isTerminal && (ndVec.at(i).lineNo < lineNum)) {
      frt = i;
    }
  }

  if (!bckFnd) cout << "Error during analysis on parse tree data" << endl;

  outVec = getSubNdVec(ndVec, frt + 1, bck);
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
      cout << "Error : Abnormal token found in the string stream. Token : " << tok << endl;
      return;
    }

  }

}





/*
 * ====================================================
 * ============ FUNCTION FOR T1 ALGORITHM =============
 * ====================================================
 */

pair<int, int> findBiggestBracketInScope(vector<NodeData> &ndVec, pair<int, int> &scope, bool &normalCompletion){
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

  pair<int, int> emptyPair = pair<int, int>(0, 0);
  if(stmtScopeVec.empty()) {
    cout << "Error : Couldn't get bracket in the scope. Abort method extraction." << endl;
    normalCompletion = false;
    return emptyPair;
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

  if(!abvChk) cout << "Error : Se Loc var scope not found." << endl;

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

  if(!abvChk || !blwChk) cout << "Error : Loc var scope not found." << endl;

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





/*
 * ====================================================
 * ============ FUNCTION FOR T2 ALGORITHM =============
 * ====================================================
 */

bool isLvalueNode(vector<NodeData> &ndVec, int idx){
// input : node vector for parsed ftn tree & index for specific node number

  return hasNodeId(ndVec, idx, 65) || hasNodeId(ndVec, idx, 123);
  // 65 : type,  123 : var_decl

}





/*
 * ====================================================
 * ============ FUNCTION FOR T3 ALGORITHM =============
 * ====================================================
 */

vector<NodeData> getRhsTnodeVec(vector<NodeData> &ndVec) {

  bool found = false;
  int assignIdx = 0;
  vector<NodeData> rhsTnodeVec;

  for(int i=0; i<ndVec.size(); i++){
    if(ndVec.at(i).isTerminal && ndVec.at(i).label == "=") {
      assignIdx = i;
      break;
    } 
  }

  for(int i=assignIdx+1; i<ndVec.size(); i++){
    if(ndVec.at(i).isTerminal) {
      // Terminal 인 노드 모으기
      if(found) {
        ndVec.at(i).isFtnCall = true;
        rhsTnodeVec.push_back(ndVec.at(i));
        found = false;
      } else{
        ndVec.at(i).isFtnCall = false;
        rhsTnodeVec.push_back(ndVec.at(i));
      }
    } else {
      if(ndVec.at(i).nodeId == 122) {
        // method invocation 인 노드 찾을 수 있게. (diff 노드 중 함수 부분 찾기)
        found = true;
      }
    }
  }

  return rhsTnodeVec;

}

vector<NodeData> getLhsTnodeVec(vector<NodeData> &ndVec) {

  bool found = false;
  int assignIdx = 0;
  vector<NodeData> lhsTnodeVec;

  for(int i=0; i<ndVec.size(); i++){
    if(ndVec.at(i).isTerminal && ndVec.at(i).label == "=") {
      assignIdx = i;
      break;
    } 
  }

  for(int i=0; i<assignIdx; i++){
    if(ndVec.at(i).isTerminal) {
      // Terminal 인 노드 모으기
      lhsTnodeVec.push_back(ndVec.at(i));
      lhsTnodeVec.back().isGenericTypeArg = false;
    }
  }

  for(int i=1; i<lhsTnodeVec.size()-1; i++){
    if(lhsTnodeVec.at(i-1).label == "<" && lhsTnodeVec.at(i+1).label == ">"){
      // 제네릭 타입 인자 토큰에 마킹
      lhsTnodeVec.at(i).isGenericTypeArg = true;
    }
  }
  
  return lhsTnodeVec;

}

vector<string> getTnodeLabelInNdVec(vector<NodeData> &ndVec){

  if(ndVec.empty()) cout << "Error : ndVec is empty. tnode cannot be found. @ getTnodeLabelInNdVec()" << endl;
  vector<string> tnodeLabelVec;
  for(int i=0; i<ndVec.size(); i++){
    if (ndVec.at(i).isTerminal) tnodeLabelVec.push_back(ndVec.at(i).label);
  }
  return tnodeLabelVec;

}





/*
 * ====================================================
 * =========== FUNCTION TYPE PARSING UTIL =============
 * ====================================================
 */

vector<string> getAnnotListFromModNdVec(vector<NodeData> &ndVec, int annotCnt){

  vector<string> annotList;
  if (annotCnt == 0) return annotList;
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
    cout << "Error : ftn annotation parsing error. @ getAnnotListFromModNdVec()" << endl;
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
    cout << "Error : ftn arg parsing error. @ getArgListFromArgNdVec()" << endl;
    return argList;
  }

}

void parseFtnType(string &fileName, string &ftnName, FtnType &ftype, vector<NodeData> &ndVec){
  
  id_init();

  ParseTree* pt = parseFile(fileName.c_str());
  if ( pt==NULL ) {
    cout << "Error: no parse tree created for file: " << fileName << endl;
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
    cout << "Error : parsing error during ftn decl line & bracket opener line parse @ parseFtnType" << endl;
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

      tmpSs.str("");
      tmpNdVec.clear();
    } else if(lineCnt == 2){
      // 2. parse return type
      tmpSs << line;
      ss2NodeVec(tmpNdVec, tmpSs);
      vector<string> rType = getTnodeLabelInNdVec(tmpNdVec);
      string rTypeStr = "";
      if(rType.size() == 0){
        cout << "Error : return type not parsed @ ftn : " << ftnName << endl;
        return;
      } else{
        for(int i=0; i<rType.size(); i++){
          rTypeStr += rType.at(i);
        }
        ftype.returnType = rTypeStr;
      }
      tmpSs.str("");
      tmpNdVec.clear();
    } else if(lineCnt == 3){
      // 3. parse ftn name
      tmpSs << line;
      ss2NodeVec(tmpNdVec, tmpSs);
      vector<string> fname = getTnodeLabelInNdVec(tmpNdVec);
      if(fname.size() != 1){
        cout << "Error : ftn name not parsed @ ftn : " << ftnName << endl;
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
        cout << "Error : arg not parsed #1 @ ftn : " << ftnName << endl;
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
          if(!labels.empty()){
            string argT = "";
            for(int i=0; i<labels.size()-1; i++){
              argT += labels.at(i);
            }
            string argN = labels.back();
            ftype.ftnArgs.push_back(pair<string, string>(argT, argN));
          } else {
            cout << "Error : parsing error in processing ftn return type." << endl;
            return;
          }
          tmpSs.str("");
          tmpNdVec.clear();
        } else {
          // get arg list from arg vec ()
          // 1. split tnode list
          // 2. push_back args from tnode list
          vector< pair<string, string> > argList = getArgListFromArgNdVec(tmpNdVec, argCnt);
          ftype.ftnArgs.insert(ftype.ftnArgs.end(), argList.begin(), argList.end());
          //ftype.ftnArgs = argList;
          tmpSs.str("");
          tmpNdVec.clear();
        }
      }
    } else if(lineCnt > 4 && fstDeli && argParsed && !sndDeli && !exctParsed) {
      if(line == "|") sndDeli = true;
      else {
        cout << "Error : arg not parsed #1 @ ftn : " << ftnName << endl;
        return;
      }
    } else if(lineCnt > 4 && fstDeli && argParsed && sndDeli && !exctParsed) {
      tmpSs << line;
      exctParsed = true;
      // TODO: only 1 exception is parsed. need to expand to accept multi exception throws.
      ss2NodeVec(tmpNdVec, tmpSs);
      vector<string> labels = getTnodeLabelInNdVec(tmpNdVec);
      if(!labels.empty()) ftype.exceptions.push_back(labels.back());
      tmpNdVec.clear();
      tmpSs.str("");
    } else if(lineCnt > 4 && fstDeli && argParsed && sndDeli && exctParsed) {
      //cout << "Error : something left to parse after exct? @ ftn : " << ftnName << endl; 
      //cout << line << endl;
      //cout << ftype.ftnName << " " << ftype.ftnArgs.front().first << endl;
      return;
    }
    
    lineCnt++;  
  }

  //ss2NodeVec(ndVec, ss);

}

NodeData findFstTnodeInNdvec(vector<NodeData> &ndVec){

  bool found = false;
  NodeData fstNode;
  if(ndVec.size() == 0) {
    cout << "Error : ndVec is empty. cannot find first node." << endl;
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
    cout << "Error : cannot find first node." << endl;
    return fstNode;
  }

}

NodeData findLstTnodeInNdvec(vector<NodeData> &ndVec){

  bool found = false;
  NodeData lstNode;
  if(ndVec.size() == 0) {
    cout << "Error : ndVec is empty. cannot find last node." << endl;
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
    cout << "Error : Cannot find last node." << endl;
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
    cout << "Error: no parse tree created for file: " << fileName << endl;
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
      cout << "Error: parsed ftn subtree cannot find first | last node on ftn : " << fname << endl;
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





/*
 * ====================================================
 * ========= FUNCTION FOR TREE MANIPULATION ===========
 * ====================================================
 */

void getPtree(string &fileName, stringstream &ss){

  ParseTree* pt = parseFile(fileName.c_str());
  
  if ( pt==NULL ) {
    cout << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }

  string fname = "f";
  pt->getRoot()->getFtnSubtree(ss, fname);

}

void dumpPtree(string &fileName){

  id_init();

  ParseTree* pt = parseFile(fileName.c_str());
  if ( pt==NULL ) {
    cout << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }

  pt->outputParseTree2Dot(fileName.c_str(), false);
  
}

void getFtnSubtree(string &fileName, string &ftnName, vector<NodeData> &ndVec){
  
  id_init();

  ParseTree* pt = parseFile(fileName.c_str());
  if ( pt==NULL ) {
    cout << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }
  
  stringstream ss;
  pt->getRoot()->getFtnSubtree(ss, ftnName);
  
  ss2NodeVec(ndVec, ss);
  
}

void getConstSubtree(string &fileName, string &cName, vector<NodeData> &ndVec){
  
  id_init();

  ParseTree* pt = parseFile(fileName.c_str());
  if ( pt==NULL ) {
    cout << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }
  
  stringstream ss;
  pt->getRoot()->getConstSubtree(ss, cName);
  
  ss2NodeVec(ndVec, ss);
  
}

vector<NodeData> getSubNdVec(vector<NodeData> &ndVec, int frt, int bck){

  vector<NodeData> subNdVec;
  for(int i=0; i<ndVec.size(); i++){
    if(i>=frt && i<=bck) subNdVec.push_back(ndVec.at(i));
  }
  return subNdVec;

}

vector< pair< vector<NodeData>, int > > getConstNdVecFromNdVec(vector<NodeData> &ndVec, string &cname){
// pair.first : 생성자 노드 벡터,  pair.second : 생성자 인자 갯수

  vector< pair< vector<NodeData>, int > > constNdVec;   
  // ndVec에서 모은 Const 노드 벡터를 각각 쪼갬.

  vector<NodeData> tmpNdVec;
  bool cFnd = false;
  int dNum = 0;
  for(int i=0; i<ndVec.size(); i++){
    if(cFnd && ndVec.at(i).depth > dNum) {
      tmpNdVec.push_back(ndVec.at(i));
    } else if(cFnd && ndVec.at(i).depth <= dNum) {
      constNdVec.push_back(pair<vector<NodeData>, int>(tmpNdVec, 0));
      tmpNdVec.clear();
      cFnd = false;
    } else if(!cFnd && ndVec.at(i).nodeId == 189) {
      tmpNdVec.push_back(ndVec.at(i));
      dNum = ndVec.at(i).depth;
      cFnd = true;
    }
  }

  bool bopen = false;
  int aCnt;

  // 생성자 인자 갯수 세기
  for(int j=0; j<constNdVec.size(); j++){
    aCnt = 0;
    for(int i=0; i<constNdVec.at(j).first.size()-1; i++){
      if(bopen){
        if(constNdVec.at(j).first.at(i).isTerminal && constNdVec.at(j).first.at(i+1).label == ")") {
          bopen = false;
          break;
        } else {
          if(constNdVec.at(j).first.at(i).nodeId == 178) aCnt++;
        }
      } else if(constNdVec.at(j).first.at(i).isTerminal) {
        if(constNdVec.at(j).first.at(i).label == cname && constNdVec.at(j).first.at(i+1).label == "(") bopen = true;
      }
    }
    constNdVec.at(j).second = aCnt;
  }

  return constNdVec;

}

int getFtnPtLineFromNdVec(vector<NodeData> &ndVec, string &fname){
// pair.first : 생성자 노드 벡터,  pair.second : 생성자 인자 갯수

  int PtLine = 0;   
  // ndVec에서 모은 Const 노드 벡터를 각각 쪼갬.

  vector<NodeData> tmpNdVec;
  bool fnd = false;
  int dNum = 0;
  for(int i=0; i<ndVec.size()-2; i++){
    if(fnd && ndVec.at(i).depth > dNum) {
      if(ndVec.at(i).nodeId == 187 && ndVec.at(i+1).nodeId == 39 && ndVec.at(i+2).label == fname){
        return ndVec.at(i+2).lineNo;
      }
      tmpNdVec.push_back(ndVec.at(i));
    } else if(fnd && ndVec.at(i).nodeId == 171) {
      fnd = false;
    } else if(!fnd && ndVec.at(i).nodeId == 113) {
      tmpNdVec.push_back(ndVec.at(i));
      dNum = ndVec.at(i).depth;
      fnd = true;
    }
  }

  return PtLine;

}

vector<NodeData> getFtnCallTNdVecFromNdVec(vector<NodeData> &ndVec, string fname){

  vector<NodeData> fcallTndVec;
  vector<NodeData> tmpNdVec;
  bool fnd = false;
  int lnum = 0;
  for(int i=0; i<ndVec.size()-2; i++){
    if(!fnd && ndVec.at(i).nodeId == 122){
      fnd = true;
    } else if(fnd && ndVec.at(i).isTerminal && tmpNdVec.empty()){
      // method_invocation 노드 발견 후 처음 말단 노드를 발견
      lnum = ndVec.at(i).lineNo;
      tmpNdVec.push_back(ndVec.at(i));
    } else if(fnd && ndVec.at(i).isTerminal && !tmpNdVec.empty() && ndVec.at(i).lineNo == lnum){
      tmpNdVec.push_back(ndVec.at(i));
      if(ndVec.at(i).label == "." && ndVec.at(i+2).label != fname){
        tmpNdVec.clear();
        lnum = 0;
        fnd = false;
      }
    } else if(fnd && ndVec.at(i).isTerminal && !tmpNdVec.empty() && ndVec.at(i).lineNo != lnum){
      fcallTndVec = tmpNdVec;
      tmpNdVec.clear();
      lnum = 0;
      fnd = false;
    }
  }

  return fcallTndVec;

}

void getPtreeVec(string &fileName, vector<NodeData> &ndVec){
  
  id_init();

  ParseTree* pt = parseFile(fileName.c_str());
  if ( pt==NULL ) {
    cout << "Error: no parse tree created for file: " << fileName << endl;
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
    cout << "Error: no parse tree created for file: " << fileName << endl;
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
    cout << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }
  
  stringstream ss;
  pt->getRoot()->getFtnSubtree(ss, ftnName);

  cout << ss.str() << endl;

}





/*
 * ====================================================
 * ========= FUNCIONS FOR CALLGRAPH ANALYSIS ==========
 * ====================================================
 */

bool has_arrow(string &s) {
	std::size_t found = s.find("->");
  	return (found!=std::string::npos);
}

string mytrim(string s) {
	std::size_t first_comma = s.find("\"");
	std::size_t second_comma = s.find("\"", first_comma + 1);
	return s.substr(first_comma + 1, second_comma - first_comma - 1);
}

void mysplit(string &line, string &caller, string &callee) {
	std::size_t found = line.find("->");
	caller = mytrim(line.substr(0, found));
	callee = mytrim(line.substr(found + 2, line.length() - found - 2));
}

bool has_java(string &str) {
  std::size_t found = str.find("java");
  return (found == 0);
}

bool c_exists(vector<string> &c_list, string &s)
{
  vector<string>::iterator it = c_list.begin();
  for (; it != c_list.end(); ++it)
  {  
    if ((*it).compare(s) == 0) return true;
  }
  return false;
}

bool cls_exists(string &cName, string &s)
{  
  if (cName.compare(s) == 0) return true;
  else return false;
}

string getPath(string &str) {
  std::size_t p_occur = str.find("(");
  std::size_t d_fst_occur = str.rfind(".", p_occur);
  std::size_t d_snd_occur = str.rfind(".", d_fst_occur - 1);

  if (d_fst_occur == 0 || d_snd_occur == 0) return "";
  else return str.substr(0, d_fst_occur);
}

string getCname(string &str) {
  std::size_t p_occur = str.find("(");
  std::size_t d_fst_occur = str.rfind(".", p_occur);
  std::size_t d_snd_occur = str.rfind(".", d_fst_occur - 1);

  if (d_fst_occur == 0 || d_snd_occur == 0) return "";
  else return str.substr(d_snd_occur + 1, (d_fst_occur - d_snd_occur - 1));
}

string getFname(string &str, int &argCnt) {
  std::size_t p_occur = str.find("(");
  std::size_t d_occur = str.rfind(".", p_occur);

  if (str.at(p_occur + 1) == ')') argCnt = 0;
  else {
    string args = str.substr(p_occur);
    argCnt = std::count(args.begin(), args.end(), ',') + 1;
  }

  if (p_occur == 0 || d_occur == 0) return "";
  else return str.substr(d_occur + 1, (p_occur - d_occur - 1));
}

void getCallGraphData(string dotfile, vector<CallGraph> &cg_list, vector<string> &c_list){
	
  ifstream infile(dotfile.c_str());	
	string lin;
  CallGraph cg;
	while (getline(infile, lin))
	{
		if (has_arrow(lin)) {
			string caller;
			string callee;
			mysplit(lin, caller, callee);
      if (!has_java(callee)) //std::cout << caller << " ---- " << callee << std::endl; // to except std library call
      {
        //cg.caller_path = caller;
        cg.caller_cname = getCname(caller);
        cg.caller_fname = getFname(caller, cg.caller_argcnt);
        //cg.callee_path = callee;
        cg.callee_cname = getCname(callee);
        cg.callee_fname = getFname(callee, cg.callee_argcnt);

        if (c_exists(c_list, cg.callee_cname)) cg_list.push_back(cg);
        
        cg.caller_cname = cg.caller_fname = cg.callee_cname = "";
      }
		}
	}

}

void getAllCallGraphData(string dotfile, vector<CallGraph> &cgVec){
	
  ifstream infile(dotfile.c_str());	
	string lin;
  CallGraph cg;
	while (getline(infile, lin))
	{
		if (has_arrow(lin)) {
			string caller;
			string callee;
			mysplit(lin, caller, callee);
      if (!has_java(callee)) //std::cout << caller << " ---- " << callee << std::endl; // to except std library call
      {
        cg.caller_path = getPath(caller);
        cg.caller_cname = getCname(caller);
        cg.caller_fname = getFname(caller, cg.caller_argcnt);
        //cg.callee_path = callee;
        cg.callee_cname = getCname(callee);
        cg.callee_fname = getFname(callee, cg.callee_argcnt);

        cgVec.push_back(cg);
        cg.caller_path = cg.caller_cname = cg.caller_fname = cg.callee_cname = cg.callee_fname = "";
      }
		}
	}

}

void getFtnCallerData(string dotfile, vector<CallGraph> &cgList, string &cName, string &fName){
	
  ifstream infile(dotfile.c_str());	
	string lin;
  CallGraph cg;
	while (getline(infile, lin))
	{
		if (has_arrow(lin)) {
			string caller;
			string callee;
			mysplit(lin, caller, callee);
      if (!has_java(callee)) //std::cout << caller << " ---- " << callee << std::endl; // to except std library call
      {
        cg.caller_path = getPath(caller);
        cg.caller_cname = getCname(caller);
        cg.caller_fname = getFname(caller, cg.caller_argcnt);
        //cg.callee_path = callee;
        cg.callee_cname = getCname(callee);
        cg.callee_fname = getFname(callee, cg.callee_argcnt);

        if (cls_exists(cName, cg.callee_cname) && cls_exists(fName, cg.callee_fname)) cgList.push_back(cg);
        
        cg.caller_path = cg.caller_cname = cg.caller_fname = cg.callee_cname = cg.callee_fname = "";
      }
		}
	}

}





/*
 * ====================================================
 * ========== TEST OUTPUT PRINTER FUNCIONS ============
 * ====================================================
 */

void printNodeVector(vector<NodeData> &ndVec){

  for(int i=0; i<ndVec.size(); i++){

    if(ndVec.at(i).isTerminal) {
      cout << "T [ nodeID : " << ' ' << " \tlabel : " << ndVec.at(i).label 
           << "\tlineNum : " << ndVec.at(i).lineNo << "\tdepth : " << ndVec.at(i).depth << " ]";
      if(ndVec.at(i).isFtnCall) cout << " - Ftn Node";
      cout << endl;
    } else {
      cout << "NT[ nodeID : " << ndVec.at(i).nodeId << " \tlabel : " << ' '
           << "\tlineNum : " << ' ' << "\tdepth : " << ndVec.at(i).depth << " ]\n";
    }

  }

}




