/*
 * Methods used for giving refactoring guides
 * These methods are used for simple analysis to get refactoring decisions
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
//  string caller_path; // caller's full path   ex) fasoo.eprint.f1....
  string caller_cname;// caller's class name
  string caller_fname;// caller's function name
//  string callee_path; // callee's full path
  string callee_cname;// callee's class name
//  string callee_fname;// callee's function name
} CallGraph;

typedef struct{
  int nodeId;
  bool isTerminal;
  string label; // empty if non-terminal
  int lineNo;   // empty if non-terminal
  int depth;    // depth of tree. same if siblings
}NodeData;

typedef struct{
  string ftnName;
  int from;
  int to;
}FtnData;

typedef struct{
    vector<string> modifiers;
    string returnType;
    vector< pair<string, string> > ftnArgs; // pair for (arg_type, arg_name). vector for multiple args
    string ftnName;
    vector<string> exceptions;
    vector<string> annotations;
    int lineNum;
    int bopenLine;
}FtnType;

pair<string, string> parseArg(vector<string> &tokVec);
void clearFtype(FtnType &ftype);
void parseFtype(vector<NodeData> &ndVec, FtnType &ftype);
bool hasNodeId(vector<NodeData> &ndVec, int idx, int id);
bool isLvalueNode(vector<NodeData> &ndVec, int idx);
void fetchClassHierarchy(string &file_name, string &classname, string &parent_classname, string &parent_intername);
void getPtree(string &fileName, stringstream &ss);
vector< pair<NodeData, int> > findNodeByLabel(vector<NodeData> &ndVec, string label);
pair<int, int> findBiggestBracketInScope(vector<NodeData> &ndVec, pair<int, int> &scope, bool &normalCompletion);
vector< pair<string, string> > findPrmtvLocVarInScope(vector<NodeData> &ndVec, pair<int, int> &scope);
vector< pair<string, string> > findLocVarInScope(vector<NodeData> &ndVec, pair<int, int> &scope);
void printNodeVector(vector<NodeData> &ndVec);
vector< pair<NodeData, int> > findNodeByLine(vector<NodeData> &ndVec, int lineNum);
int lineParenthesisChk(vector<NodeData> &ndVec, int lineNum);
void getFtnSubtree(string &fileName, string &ftnName, vector<NodeData> &ndVec);
void parseFtnType(string &fileName, string &ftnName, FtnType &ftype, vector<NodeData> &ndVec);
vector<string> getTnodeLabelInNdVec(vector<NodeData> &ndVec);
void getAllFtnData(string &fileName, vector<FtnData> &fdVec);
void dumpPtree(string &fileName);
void print2ssFtnSubtree(string &fileName, string &ftnName);
void getPtreeVec(string &fileName, vector<NodeData> &ndVec);
void printss(string &fileName);
string getClassModifier(string &file_name, string &class_type);