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

typedef struct{
  int nodeId;
  bool isTerminal;
  string label; // empty if non-terminal
  int lineNo;   // empty if non-terminal
  int depth;    // depth of tree. same if siblings
}NodeData;

bool has_node_id(vector<NodeData> &ndVec, int idx, int id);
bool is_lvalue_node(vector<NodeData> &ndVec, int idx);
void fetchClassHierarchy(string &file_name, string &classname, string &parent_classname, string &parent_intername);
void getPtree(string &fileName, stringstream &ss);
vector< pair<NodeData, int> > find_node_by_label(vector<NodeData> &ndVec, string label);
pair<int, int> find_biggest_bracket_in_scope(vector<NodeData> &ndVec, pair<int, int> &scope);
void print_node_vector(vector<NodeData> &ndVec);
vector< pair<NodeData, int> > find_node_by_line(vector<NodeData> &ndVec, int lineNum);
int line_parenthesis_check(vector<NodeData> &ndVec, int lineNum);
void getFtnSubtree(string &fileName, string &ftnName, vector<NodeData> &ndVec);
void dumpPtree(string &fileName);
void print2ssFtnSubtree(string &fileName, string &ftnName);
void getPtreeVec(string &fileName, vector<NodeData> &ndVec);
void printss(string &fileName);
string getClassKeyword(string &file_name, string &class_type);