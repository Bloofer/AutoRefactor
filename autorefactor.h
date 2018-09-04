#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <ctype.h>
#include "dtl/dtl/dtl.hpp"
#include "include/ptree.h"
#include "include/treeutil.h"
#include "treeTra/token-tree-map.h"
using namespace std;

int n; // number of clone sites

// refactor data structures

// TODO: to impl read meaningful callers to patch
// struct type for caller datas
typedef struct{
    string fileName;
    string callerObjectName;
    string callerObjectFtnName;
    int argNum;
    string originalFtnName;
    vector<string> callArgs;
    int lineNum;
}Caller;

// struct type for clone datas
typedef struct{
    string fileName;
    int from, to;
    vector<string> cloneSnippet;
    vector< pair<string, int> > argCalls; // for type4. <arg obj ftn call name, call line> vector
    int cloneSize;
    vector<Caller> callers;
}CloneData;
vector<CloneData> cloneDatas;

typedef enum {
    CLASS,
    ABSTRACT_CLASS,
    INTERFACE,
    DONT_KNOW
} class_type;

typedef struct{
    vector<string> keywords;
    class_type ctype;
    string cname;
    int lineNum;
}ClassType;

typedef struct{
    vector<string> keywords;
    string returnType;
    vector< pair<string, string> > ftnArgs; // pair for (arg_type, arg_name). vector for multiple args
    string ftnName;
    int lineNum;
}FtnType;

typedef enum {
    T1,
    T2
} clone_type;

// function variable datas
vector<string> importClassVec; // vector holding imported class datas(type, name)
vector< pair<string, string> > classMemVarVec; // vector holding class member var datas(type, name)

map<string, string> classHierarchy;
// (child -> parent) map
// class hierarchy of the whole project.
// TODO: need to impl the ftn which gathers this data

map<string, string> classToFileMap;
// (class name -> file location) map
// this directs the exact location of the class file
// TODO: need to impl the ftn which gathers this data

// temporary variable to save the clone code snippets
vector<string> tempClone;
vector<string> patchCode;
int tempCodeLine;
string cloneFtnName = "cloneFtn";
int cloneFtnNum = 1;

// logger & variables
int beforePatchLoc;
int afterPatchLoc;
int reducedLoc;

void read_file(char* alarmFile); // reads input file including clone data
int get_file_line(string fileName);
void refactor(clone_type ct); // the main function for auto refactor

// method extraction for 4 types of code clones
void em_type1();
void em_type2();

// string utility functions
bool are_same(string s1, string s2);
bool only_spaces(string str);
bool contains(string str, string word);
int min_pos(int a, int b);
string int_to_str(int n);
int str_to_int(const char *s);

// communal functions for all types
void parse_ftn_type(string s, FtnType &ftype);
void patch_callers(Caller c, string newFname, int flag);
int get_line_offset(vector<NodeData> &ndVec, string &ftnName, int from);
vector<int> get_diff(CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2);
void parse_class_member_vars(string fileName);

// functions for type 1 (extract method)
pair<int, int> get_common_part();
void patch_code(string fileName); // replace code clone with new function
void trim_code(int p, int q);

// functions for type 2 (merge method)
vector<int> get_diff(CloneData &c1, CloneData &c2);
bool int_vec_contains(vector<int> &iv, int i);
void merge_clone_ftn(string fileName, CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2);

// test functions
void test_print(); // test printer for check cloneDatas
void print_code(vector<string> code);
void test_diff();
void print_ftn_type(FtnType &f);
void print_arg_calls(CloneData &cd);
void print_caller(CloneData &cd);
void print_class_n_ftn_type(vector< pair< vector<string>, int > > &classNftnTypeDef);
void print_class_type(ClassType &c);