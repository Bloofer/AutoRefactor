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
#include "include/fileioutil.h"
using namespace std;

int n; // number of clones
bool nc = true; // checker for code patch completes normally. nc stands for normal completion.

// TODO: to impl read meaningful callers to patch
// struct type for caller datas
typedef struct{
    string realPath;
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
    string ftnName;
}CloneData;
vector<CloneData> cloneDatas;
vector<FtnType> cloneFtnTypes;

typedef enum {
    CLASS,
    ABSTRACT_CLASS,
    INTERFACE,
    DONT_KNOW
} class_type;

typedef struct{
    vector<string> modifiers;
    class_type ctype;
    string cname;
    int lineNum;
}ClassType;

typedef struct{
    int diffType; // others : 0, return stmt : 1, var decl : 2
    int lineNum; // line num in the file
    bool isRef; // (if diff stmt is var decl,) check the decl type is reference
    string typeName; // (if diff stmt is var decl,) fetch the decl type name
    string varName; // (if diff stmt is var decl,) fetch the decl var name
}DiffInfo;

typedef enum {
    T1,
    T2,
    T3,
    ERR
} clone_type;

typedef enum {
    ALL, // show all results and output
    RST, // show only result
    COD // show only output
} RunOption;
RunOption runOption;

// function variable datas
vector<string> importClassVec; // vector holding imported class datas(type, name)
vector< pair<string, string> > classMemVarVec; // vector holding class member var datas(type, name)

// primtive type 2 object vector
// used for T3 lambda type patching
// Boolean, Byte, Character, Double, Float, Integer, Long, Short, Void.
map<string, string> prmtv2ObjMap;

map<string, string> classHierarchy;
// (child -> parent) map
// class hierarchy of the whole project.
// TODO: need to impl the ftn which gathers this data

vector<CallGraph> callGraphVec;
// 전체 프로젝트의 CallGraph 정보를 가지는 벡터
// 처음에 fpath2CnamePairVec와 같이 한번 전체 프로젝트 내 생성되고
// 각 중복 인스턴스별로 유지되어 사용된다.
// T2 Caller Patch에 사용

vector< pair<string, string> > fpath2CnamePairVec;
// (File absolute path, Class name) pair vector
// 파일 I/O에 사용.
// 디렉토리를 읽은 후 자바 파일들에 대해서만 (절대경로, 클래스명) 벡터를 생성
// T2 Caller Patch에 사용

map<string, string> classToFileMap;
// (class name -> file location) map
// this directs the exact location of the class file
// TODO: need to impl the ftn which gathers this data

// temporary variable to save the clone code snippets
vector<string> tempClone; // T1 : extracted method, T2 : merged method
vector<string> orgClone1; // T1 : clone method1 (patched clone with ftn call)
vector<string> orgClone2; // T1 : clone method2 (patched clone with ftn call)
vector<string> patchCode; // final result of the patched source code
int tempCodeLine;

// logger & variables
int beforePatchLoc;
int afterPatchLoc;
int reducedLoc;

void readFile(char* alarmFile); // reads input file including clone data
int getFileLine(string fileName);
void refactor(clone_type ct); // the main function for auto refactor

// method extraction for 4 types of code clones
void patchT1();
void em_type2();

// string utility functions
bool strAreSame(string s1, string s2);
bool strOnlySpaces(string str);
string int2str(int n);
int intMin(int a, int b);
bool intVecContains(vector<int> &iv, int i);
bool strVecExists(vector<string> &sv, string s);
int ssPairVecSndExists(vector< pair<string, string> > &sv, string s);
bool cmpSsPairVec(vector< pair<string, string> > &sv1, vector< pair<string, string> > &sv2);

// communal functions for all types
void patchCaller(Caller c, string newFname, int flag);
void patchCaller2(Caller c, string fname, string newFname, int flag);
int getLineOffset(vector<NodeData> &ndVec, string &ftnName, int from);
void parseClassMemVars(string fileName);
bool compFtype(FtnType &f1, FtnType &f2);
clone_type getCloneType();
void reportResult();

// functions for type 1 (extract method)
pair<int, int> getCommonPart(CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2, bool &normalCompletion);
vector< pair<string, string> > getSeVarSet(CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2, pair<int, int> &scope, bool &normalCompletion);
vector< pair<string, string> > getVarSet(CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2, pair<int, int> &scope, bool &normalCompletion);
void extractMethod(string fileName, CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2, pair<int, int> &scope, vector< pair<string, string> > &varSet, vector< pair<string, string> > &seVarSet);

// functions for type 2 (merge method)
void getCallerInfo(string &cname, string &fname, vector<CallGraph> &cgVec, vector<Caller> &callerVec);
vector<int> getDiff(CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2, vector<DiffInfo> &diffInfo, bool &normalCompletion);
void mergeMethod(string fileName, CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2, bool &normalCompletion);

// clone patch main functions (for T1/T2/T3)
void patchT1();
void patchT2();
void patchT3(); // TODO: need maintain

// test functions
void testPrintCloneData(); // test printer for check cloneDatas
void testPrintCaller(CloneData &cd);
void testPrintCode(vector<string> code);
void testPrintFtnType(FtnType &f);
void testPrintArgCalls(CloneData &cd);
void testPrintClassNftnType(vector< pair< vector<string>, int > > &classNftnTypeDef);
void testPrintClassType(ClassType &c);
void testPrintFdVec(vector<FtnData> &fdVec);
void testPrintNdPairVec(vector< pair<NodeData, int> > &ndPairVec);
void testPrintDiffInfo(DiffInfo &dInfo);
void testPrintCallerVec(vector<Caller> &cVec);