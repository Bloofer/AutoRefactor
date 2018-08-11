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
#include "include/refactorguide.h"
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
    T2,
    T3,
    T4
} clone_type;

string typeArray[8] = {"byte", "short", "int", "long", 
     "float", "double", "boolean", "char"};
vector<string> javaPrimitiveDataTypes(&typeArray[0], &typeArray[0]+8); 
// TODO: maybe need to update more java types?

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

void read_file(char* alarmFile); // reads input file including clone data
void refactor(clone_type ct); // the main function for auto refactor

// method extraction for 4 types of code clones
void em_type1n2();
void em_type3();
void em_type4();

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

// functions for type 1 & 2
vector<int> get_diff(CloneData &c1, CloneData &c2);
bool int_vec_contains(vector<int> &iv, int i);
void merge_clone_ftn(string fileName, CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2);

// functions for type 3
pair<int, int> get_common_part();
void patch_code(string fileName); // replace code clone with new function
void trim_code(int p, int q);

// functions for type 4
bool chk_sibling(string arg1, string arg2);
class_type get_class_type(string c, int &classDefLine);
void fetch_arg_calls(CloneData &c1, CloneData &c2, string arg1Name, string arg2Name, vector<int> diffLine);
bool is_alpha_or_parenthesis(char c);
void gather_ftn_def(string fileName, vector< pair< vector<string>, int > > &classNftnTypeDef);
void parse_class_n_ftn_type(ClassType &c, vector<FtnType> &fv, vector< pair< vector<string>, int > > &classNftnTypeDef);
bool comp_ftn_type(FtnType &f1, FtnType &f2);
void ftnType_to_ftn_def(FtnType &f, string &s, bool isAbs);
void patch_arg_parent_code(string fileName, ClassType ct, vector<FtnType> &pft, vector<FtnType> &c1ArgFtVec, vector<FtnType> &c2ArgFtVec, vector<string> &undefFtn);
void pull_up_arg(CloneData &c1, CloneData &c2, string pfileName, ClassType &pct, vector<FtnType> &pft, vector<FtnType> &c1ArgFtVec, vector<FtnType> &c2ArgFtVec);
void merge_t4_clone_ftn(string fileName, CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2); 

// test functions
void test_print(); // test printer for check cloneDatas
void print_code(vector<string> code);
void test_diff();
void print_ftn_type(FtnType &f);
void print_arg_calls(CloneData &cd);
void print_caller(CloneData &cd);
void print_class_n_ftn_type(vector< pair< vector<string>, int > > &classNftnTypeDef);
void print_class_type(ClassType &c);