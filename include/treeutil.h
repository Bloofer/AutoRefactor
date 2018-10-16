/*
 * YACC 파서에서 만들어낸 AST를 분석/이용하는 모듈
 * 트리/노드벡터 관련 함수들 구현
 * Implemented by jmyang <jmyang@ropas.snu.ac.kr>
 */

#include "ptree.h"
#include <sys/types.h>
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
  string caller_path; // caller's full path   ex) fasoo.eprint.f1....
  string caller_cname;// caller's class name
  string caller_fname;// caller's function name
  int caller_argcnt; // caller's arg number
//  string callee_path; // callee's full path
  string callee_cname;// callee's class name
  string callee_fname;// callee's function name
  int callee_argcnt; // callee's arg number
} CallGraph;

typedef struct{
  int nodeId;
  bool isTerminal;
  string label; // empty if non-terminal
  int lineNo;   // empty if non-terminal
  int depth;    // depth of tree. same if siblings
  bool isFtnCall; // used for T3 code patch alg.
                 // true if the node is 
}NodeData;

typedef struct{
  string ftnName;
  int from;
  int to;
}FtnData;

typedef struct{
    vector<string> modifiers;
    string returnType;
    bool rTypeRef; // if the return type of ftn is reference, else primitive
    vector< pair<string, string> > ftnArgs; // pair for (arg_type, arg_name). vector for multiple args
    string ftnName;
    vector<string> exceptions;
    vector<string> annotations;
    int lineNum;
    int bopenLine;
}FtnType;

// Communal functions for all
int str2int(const char *s);
bool hasNodeId(vector<NodeData> &ndVec, int idx, int id);
void fetchClassHierarchy(string &file_name, string &classname, string &parent_classname, string &parent_intername);
void fetchClassName(string &file_name, string &classname);
vector< pair<NodeData, int> > findNodeByLabel(vector<NodeData> &ndVec, string label);
vector< pair<NodeData, int> > findNodeByLine(vector<NodeData> &ndVec, int lineNum);
vector<NodeData> findNodeByLineWithNt(vector<NodeData> &ndVec, int lineNum);
int lineParenthesisChk(vector<NodeData> &ndVec, int lineNum);
void ss2NodeVec(vector<NodeData> &ndVec, stringstream &ss);

// Functions for T1 Algorithm
pair<int, int> findBiggestBracketInScope(vector<NodeData> &ndVec, pair<int, int> &scope, bool &normalCompletion);
vector< pair<string, string> > findPrmtvLocVarInScope(vector<NodeData> &ndVec, pair<int, int> &scope);
vector< pair<string, string> > findLocVarInScope(vector<NodeData> &ndVec, pair<int, int> &scope);

// Functions for T2 Algorithm
bool isLvalueNode(vector<NodeData> &ndVec, int idx);

// Functions for T3 Algorithm
vector<NodeData> getRhsTnodeVec(vector<NodeData> &ndVec);
vector<string> getTnodeLabelInNdVec(vector<NodeData> &ndVec);

// Function type parsing utils
vector<string> getAnnotListFromModNdVec(vector<NodeData> &ndVec, int annotCnt);
vector< pair<string, string> > getArgListFromArgNdVec(vector<NodeData> &ndVec, int argCnt);
void parseFtnType(string &fileName, string &ftnName, FtnType &ftype, vector<NodeData> &ndVec);
NodeData findFstTnodeInNdvec(vector<NodeData> &ndVec);
NodeData findLstTnodeInNdvec(vector<NodeData> &ndVec);
bool isEmptyNodeData(NodeData &nd);
void getAllFtnData(string &fileName, vector<FtnData> &fdVec);

// Functions for tree manipulation
void getPtree(string &fileName, stringstream &ss);
void dumpPtree(string &fileName);
void getFtnSubtree(string &fileName, string &ftnName, vector<NodeData> &ndVec);
void getConstSubtree(string &fileName, string &cName, vector<NodeData> &ndVec);
vector<NodeData> getSubNdVec(vector<NodeData> &ndVec, int frt, int bck);
vector< pair< vector<NodeData>, int > > getConstNdVecFromNdVec(vector<NodeData> &ndVec, string &cname);
vector<NodeData> getFtnCallTNdVecFromNdVec(vector<NodeData> &ndVec, string fname);
void getPtreeVec(string &fileName, vector<NodeData> &ndVec);
void printss(string &fileName);
void print2ssFtnSubtree(string &fileName, string &ftnName);

// Functions for callgraph analysis
bool has_arrow(string &s);
string mytrim(string s);
void mysplit(string &line, string &caller, string &callee);
bool has_java(string &str);
bool c_exists(vector<string> &c_list, string &s);
bool cls_exists(string &cName, string &s);
string getPath(string &str);
string getCname(string &str);
string getFname(string &str, int &argCnt);
void getCallGraphData(string dotfile, vector<CallGraph> &cg_list, vector<string> &c_list);
void getAllCallGraphData(string dotfile, vector<CallGraph> &cgVec);
void getFtnCallerData(string dotfile, vector<CallGraph> &cgList, string &cName, string &fName);
bool compare_cg (CallGraph &fst, CallGraph &snd);
bool same_cg (CallGraph cg1, CallGraph cg2);

// Functions for test print
void printNodeVector(vector<NodeData> &ndVec);