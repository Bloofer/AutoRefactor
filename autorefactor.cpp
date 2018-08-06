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

typedef struct{
    vector<string> keywords;
    string returnType;
    vector< pair<string, string> > ftnArgs; // pair for (arg_type, arg_name). vector for multiple args
    string ftnName;
}FtnType;

typedef enum {
    T1,
    T2,
    T3,
    T4
} clone_type;

typedef enum {
    CLASS,
    ABSTRACT_CLASS,
    INTERFACE,
    DONT_KNOW
} class_type;

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
string itos(int n);

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
void pull_up_arg();
class_type get_class_type(string c, int &classDefLine);
void merge_t4_clone_ftn(string fileName, CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2); 

// test functions
void test_print(); // test printer for check cloneDatas
void print_code(vector<string> code);
void test_diff();
void print_ftn_type(FtnType &f);
void print_arg_calls(CloneData &cd);


/*
 * ====================================================
 * =============== FILE I/O FUNCTIONS =================
 * ====================================================
 */

// maybe replace with merging the code to refactor_guide?
void read_file(char* alarmFile){

    ifstream cfile(alarmFile);
    cfile >> n;

    CloneData tmpCdata;

    for(int i=0; i<n; i++){
        cfile >> tmpCdata.fileName >> tmpCdata.from >> tmpCdata.to;
        tmpCdata.cloneSize = tmpCdata.to - tmpCdata.from + 1;

        ifstream ccode(tmpCdata.fileName.c_str());
        int line = 1;
        string temp;
        while (line <= tmpCdata.to) {
            getline(ccode, temp);
            if (line >= tmpCdata.from) tmpCdata.cloneSnippet.push_back(temp);
            line++; 
        }

        cloneDatas.push_back(tmpCdata);
        tmpCdata.fileName = "";
        tmpCdata.from = tmpCdata.to = tmpCdata.cloneSize = 0;
        tmpCdata.cloneSnippet.clear();
    }

    int callerNum;
    Caller tmpCaller;

    for(int i=0; i<n; i++){
        cfile >> callerNum;
        for(int j=0; j<callerNum; j++){
            cfile >> tmpCaller.fileName;
            cfile >> tmpCaller.callerObjectName >> tmpCaller.callerObjectFtnName >> tmpCaller.originalFtnName;
            cfile >> tmpCaller.argNum;
            for(int k=0; k<tmpCaller.argNum; k++){
                string tmpStr;
                cfile >> tmpStr;
                tmpCaller.callArgs.push_back(tmpStr);
            }
            cfile >> tmpCaller.lineNum;
            cloneDatas[i].callers.push_back(tmpCaller);
            tmpCaller.fileName = tmpCaller.callerObjectName = tmpCaller.callerObjectFtnName = "";
            tmpCaller.argNum = tmpCaller.lineNum = 0;
            tmpCaller.callArgs.clear();
        }
    }

}


/*
 * ====================================================
 * ============ STRING UTILITY FUNCTIONS ==============
 * ====================================================
 */

bool are_same(string s1, string s2){

    if(only_spaces(s1) && only_spaces(s2)) return true;
    else if(only_spaces(s1) || only_spaces(s2)) return false;

    dtl::Diff< char, string > strDiff(s1, s2);
    strDiff.compose();
    return (strDiff.getEditDistance() == 0);

}

bool only_spaces(string str){
    // checks if certain string has only spaces
    // this function is for checking white space in the program code
    if(str.find_first_not_of(" \t\r\n") != std::string::npos) return false;
    else return true;
}

bool contains(string str, string word){
    // checks if str contains word
    return (str.find(word) < str.size() && str.find(word) >= 0);

}

int min_pos(int a, int b){
    if (a >= 0 && b >= 0) return a < b ? a : b;
    else return a > b ? a : b;
}

string itos(int n){
    ostringstream ss;
    ss << n;
    return ss.str();
}




/*
 * ====================================================
 * =========== COMMUNAL FUNCTIONS FOR ALL =============
 * ====================================================
 */

void parse_ftn_type(string s, FtnType &ftype){
    
    if (s.find(')') == string::npos) { 
        cerr << "Error : parse_ftn_type() cannot parse \"" << s << "\" without parentheses closure" << endl;
        return;
    }

    vector<string> tokens;
    string ns = s.substr(s.find_first_not_of(" \t\r\n"));
    
    int prevPos = s.find_first_of(" \t\r\n");
    int emptyPoint = ns.find(' ');
    string token;

    // 1. parse ftn type and ftn name
    while(emptyPoint <= ns.find('(')){
        token = ns.substr(0, emptyPoint);
        tokens.push_back(token);
        ns = ns.substr(emptyPoint);
        ns = ns.substr(ns.find_first_not_of(" \t\r\n"));
        prevPos += (emptyPoint + 1);
        emptyPoint = ns.find(' ');
    }

    if (ns.find('(') > 0) {
        token = ns.substr(0, ns.find('('));
        tokens.push_back(token);
    }

    reverse(tokens.begin(), tokens.end());
    ftype.ftnName = tokens[0];
    ftype.returnType = tokens[1];

    if(tokens.size() > 2){
        for(int i=tokens.size()-1; i>=2; i--)
        ftype.keywords.push_back(tokens[i]);
    }

    ns = s.substr(s.find('(') + 1);
    ns = ns.substr(ns.find_first_not_of(" \t\r\n"));
    pair<string, string> argPair;

    // 2. parse arg type and arg name
    emptyPoint = ns.find(' ');
    while(emptyPoint <= ns.find(')') && ns.find_first_of('{') != 0){
        argPair.first = ns.substr(0, emptyPoint);
        ns = ns.substr(emptyPoint);
        ns = ns.substr(ns.find_first_not_of(" \t\r\n"));
        
        emptyPoint = min_pos(ns.find(' '), ns.find(','));
        emptyPoint = min_pos(emptyPoint, ns.find(')'));
        argPair.second = ns.substr(0, emptyPoint);
        ns = ns.substr(emptyPoint + 1);

        if(ns.find(',') > 0){
            ns = ns.substr(ns.find_first_not_of(" \t\r\n"));
            if(ns.find(',') == 0) {
                ns = ns.substr(1);
                if(ns.find_first_of(' ') == 0) ns = ns.substr(ns.find_first_not_of(" \t\r\n"));
            }
        } else {
            ns = ns.substr(1);
            ns = ns.substr(ns.find_first_not_of(" \t\r\n"));
        }

        ftype.ftnArgs.push_back(argPair);
        emptyPoint = ns.find(' ');
    }

}

void patch_callers(Caller c, string newFname, int flag){
    // function for fetching caller datas
    // using data from the alarm file which are parsed from DOT file

    // Get the call site code line too. to use for caller patching
    ifstream pfile(c.fileName.c_str());
    string line;
    vector<string> tempCode;
    int callerLine = c.lineNum;
    int lineCnt = 0; // line counter
    while(getline(pfile, line)) {
        tempCode.push_back(line);
        lineCnt++;
    }

    string patchLine = tempCode[c.lineNum-1];
    bool found = false;
    int ftnFront, ftnRear;
    ftnFront = ftnRear = 0;

    while(!found){
        ftnFront = patchLine.find_first_of(c.originalFtnName, ftnFront);
        if (patchLine.at(ftnFront + c.originalFtnName.size()) == '(' && patchLine.at(ftnFront - 1) == '.') {
            found = true;
            ftnRear = patchLine.find_first_of(')', ftnFront);
        } else if (patchLine.at(ftnFront + c.originalFtnName.size()) == ' '){
            ftnFront += patchLine.substr(ftnFront).find_first_not_of(" \t\r\n");
            if (patchLine.at(ftnFront + c.originalFtnName.size()) == '(') {
                found = true;
                ftnRear = patchLine.find_first_of(')', ftnFront);
            }
        } else {
            ftnFront++;
        }
    }
    
    string strFront = patchLine.substr(0, ftnFront) + newFname + "(";
    string strRear = itos(flag) + ")" + patchLine.substr(ftnRear + 1);

    patchLine = strFront;
    for(int i=0; i<c.argNum; i++){
        patchLine += c.callArgs[i] + ", ";
    }
    patchLine += strRear;
    tempCode[c.lineNum-1] = patchLine;    

    cout << "Patching callers ...\n";
    cout << "(This will be replaced with actual file write operations)\n";
    print_code(tempCode); // TODO: need to replace this with file write operations

} 

vector<int> get_diff(CloneData &c1, CloneData &c2){
    // function for getting diff part of two clone datas
    vector<int> diffLine;

    // 1. compare two clone datas (function-wise)
    vector<string>::iterator it1 = c1.cloneSnippet.begin();
    vector<string>::iterator it2 = c2.cloneSnippet.begin();
    int idx = 0;

    // 2. put diff part offset line in the vector (this should except first/last line - b.c. ftn decl & closure)
    for(; it1 != c1.cloneSnippet.end() && it2 != c2.cloneSnippet.end(); ++it1, ++it2){
        if (!are_same((*it1), (*it2)) && idx != 0) diffLine.push_back(idx);
        idx++;
    }

    // 3. return the vector
    return diffLine;
}




/*
 * ====================================================
 * ============ FUNCTIONS FOR TYPE 1 & 2 ==============
 * ====================================================
 */

bool int_vec_contains(vector<int> &iv, int i){
    return ( find(iv.begin(), iv.end(), i) != iv.end() );
}

void merge_clone_ftn(string fileName, CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2){
    
    string newFtnName = f1.ftnName + f2.ftnName;
    // 1. substitute caller function name with new one.

    for(int i=0; i<c1.callers.size(); i++){
        patch_callers(c1.callers[i], newFtnName, 0);
    }

    for(int i=0; i<c2.callers.size(); i++){
        patch_callers(c2.callers[i], newFtnName, 1);
    }
    

    vector<int> diffLine = get_diff(cloneDatas.front(), cloneDatas.back()); // TODO: refactor this?
    // 2. insert procedure branches using if/else statements using flag.
    // use diffLine to get the diff lines
    int tabIdx = c1.cloneSnippet.front().find_first_not_of(" \t\r\n"); // this is for code formatting
    string tabStr = c1.cloneSnippet.front().substr(0, tabIdx);


    // 3. insert flag at the ftn decl.
    // use FtnType to not get new function name & arg name
    string ftnDecl = tabStr;
    for(int i=0; i<f1.keywords.size(); i++){
        ftnDecl += (f1.keywords[i] + " ");
    }

    ftnDecl += (f1.returnType + " " + newFtnName + "(");
    for(int i=0; i<f1.ftnArgs.size(); i++){
        ftnDecl += f1.ftnArgs[i].first;
        ftnDecl += " ";
        ftnDecl += f1.ftnArgs[i].second;
        ftnDecl += ", ";
    }
    ftnDecl += "int flag) {"; // TODO: maybe need to refactor b.c. parenthesis not in first line?
    tempClone.push_back(ftnDecl);

    for(int i=1; i<c1.cloneSize; i++){
        if (!int_vec_contains(diffLine, i)) tempClone.push_back(c1.cloneSnippet[i]);
        else {
            tabIdx = c1.cloneSnippet[i].find_first_not_of(" \t\r\n"); // this is for code formatting
            tabStr = c1.cloneSnippet[i].substr(0, tabIdx);
            tempClone.push_back(tabStr + "if(flag == 0) " + c1.cloneSnippet[i].substr(tabIdx));
            tempClone.push_back(tabStr + "else if(flag == 1) " + c2.cloneSnippet[i].substr(tabIdx));
        }
    }

    ifstream pfile(c1.fileName.c_str());
    string line;

    int lineCnt = 1; // line counter
    while(getline(pfile, line)) {
        //if (lineCnt >= c1.from && lineCnt <= c1.to) continue;
        //if (lineCnt >= c2.from && lineCnt <= c2.to) continue;
        //cout << line << endl;
        if(lineCnt == c1.from) patchCode.insert(patchCode.end(), tempClone.begin(), tempClone.end());
        if(lineCnt == c2.to + 1) {
            if(only_spaces(line)) { lineCnt++; continue; }
        }
        if(!(lineCnt >= c1.from && lineCnt <= c1.to) && !(lineCnt >= c2.from && lineCnt <= c2.to)) patchCode.push_back(line);
        
        lineCnt++;
    }

    cout << "Patching clones ...\n";
    cout << "(This will be replaced with actual file write operations)\n";
    print_code(patchCode); // TODO: need to replace this with file write operations

}


/*
 * ====================================================
 * =============== FUNCTIONS FOR TYPE 3 ===============
 * ====================================================
 */


pair<int, int> get_common_part(CloneData &c1, CloneData &c2){

    // compare two clone datas
    vector<string>::iterator it1 = c1.cloneSnippet.begin();
    vector<string>::iterator it2 = c2.cloneSnippet.begin();
    
    int from = 0;
    int to = 0;
    int count = 1;
    bool same = false;
    bool check = false;

    while (it1 != c1.cloneSnippet.end() || it2 != c2.cloneSnippet.end()){

        if(are_same((*it1), (*it2)) && !same) {
            from = count;
            same = true;
        } else if(!are_same((*it1), (*it2)) && same && !check){
            to = count - 1;
            check = true;
        }

        count++;
        if(it1 != c1.cloneSnippet.end()) ++it1;
        if(it2 != c2.cloneSnippet.end()) ++it2;
    }

    pair<int, int> p = pair<int, int>(from, to);

    return p;

}

string get_clone_ftn_name(){

    ostringstream ftnNum;
    ftnNum << cloneFtnNum;
    string ftnName = cloneFtnName + ftnNum.str() + "()";
    return ftnName;

}

void patch_code(string fileName){

    ifstream pfile(fileName.c_str());
    string line;
    int classLine; // line number of class declaration
    int lineCnt = 0; // line counter
    string ftnDef, ftnCls, ftnCall; // patch function code definition line & closure line
    ftnCall = "      " + get_clone_ftn_name() + ";";

    while(getline(pfile, line)) {
        lineCnt++;

        if (contains(line, "public") && contains(line, "class")) {
            patchCode.push_back(line);
            istringstream iss(line);
            string a, b;
            iss >> a >> b;
            if (!a.compare("public") && !b.compare("class")) {
                ftnDef = "    public void " + get_clone_ftn_name() + " {";
                ftnCls = "    }";
                patchCode.push_back("");
                patchCode.push_back(ftnDef);
                patchCode.insert(patchCode.end(), tempClone.begin(), tempClone.end());
                patchCode.push_back(ftnCls);
                classLine = lineCnt;
            }
        } else {

            if ((lineCnt >= cloneDatas.front().from && lineCnt < cloneDatas.front().to) 
               || (lineCnt >= cloneDatas.back().from && lineCnt < cloneDatas.back().to)) continue;
            else if (lineCnt == cloneDatas.front().to || lineCnt == cloneDatas.back().to) patchCode.push_back(ftnCall);
            else patchCode.push_back(line);

        }

    }
    cloneFtnNum++;

}

void trim_code(int p, int q){
// trim the clone part of the cloneDatas

    int from = cloneDatas.front().from;
    int to = cloneDatas.front().to;
    cloneDatas.front().from = from + (p - 1);
    cloneDatas.front().to = from + (q - p);

    from = cloneDatas.back().from;
    to = cloneDatas.back().to;
    cloneDatas.back().from = from + (p - 1);
    cloneDatas.back().to = from + (q - p);

}


/*
 * ====================================================
 * =============== FUNCTIONS FOR TYPE 4 ===============
 * ====================================================
 */


// TODO: need to impl this

    void get_class_hierarchy() {

        // this is just for testing
        // TODO: need to finish impl this
        classHierarchy.insert(make_pair("Car", "Vehicle"));
        classHierarchy.insert(make_pair("Truck", "Vehicle"));
        classToFileMap.insert(make_pair("Car", "/home/yang/Sources/AutoRefactor/toyex/t4/Car.java"));
        classToFileMap.insert(make_pair("Truck", "/home/yang/Sources/AutoRefactor/toyex/t4/Truck.java"));
        classToFileMap.insert(make_pair("Vehicle", "/home/yang/Sources/AutoRefactor/toyex/t4/Vehicle.java"));
        classToFileMap.insert(make_pair("HelloWorld", "/home/yang/Sources/AutoRefactor/toyex/t4/HelloWorld.java"));

    }

    // 2. check clone ftn arg are sibling 
    bool chk_sibling(string arg1, string arg2) {

        // TODO: maybe need to get whole project class hierarchy?
        // need to find out what to do ...

        return (classHierarchy.find(arg1)->second == classHierarchy.find(arg2)->second); 

    }

    class_type get_class_type(string c, int &classDefLine){

        string fileName = classToFileMap.find(c)->second;
        ifstream pfile(fileName.c_str());
        string line;
        int classLine;
        int lineCnt = 0;
        
        while(getline(pfile, line)) {
            if (contains(line, "public") || contains(line, "private") || contains(line, "protected")){
                istringstream iss(line);
                string t1, t2, t3;
                iss >> t1 >> t2 >> t3;
                if ((t1 != "public") && (t1 != "private") && (t1 != "protected")){
                    lineCnt++;
                    continue;        
                } else {
                    if (t2 == "class") {classDefLine = lineCnt; return CLASS;}
                    else if (t2 == "interface") {classDefLine = lineCnt; return INTERFACE;}
                    else if (t2 == "abstract") if (t3 == "class") {classDefLine = lineCnt; return ABSTRACT_CLASS;}
                }
            }
            lineCnt++;
        }

        return DONT_KNOW;

    }

    void fetch_arg_calls(CloneData &c1, CloneData &c2, string arg1Name, string arg2Name, vector<int> diffLine){
        
        int callIdx;
        string callStr;

        for(vector<int>::iterator it = diffLine.begin(); it != diffLine.end(); ++it){
            callIdx = c1.cloneSnippet[(*it)].find_first_of(arg1Name);
            callStr = c1.cloneSnippet[(*it)].substr(callIdx+arg1Name.size()+1);
            callIdx = callStr.find_first_of("(");
            callStr = callStr.substr(0, callIdx);
            c1.argCalls.push_back(pair<string, int>(callStr, (*it)));
            //cout << callStr << endl;
            callIdx = c2.cloneSnippet[(*it)].find_first_of(arg2Name);
            callStr = c2.cloneSnippet[(*it)].substr(callIdx+arg2Name.size()+1);
            callIdx = callStr.find_first_of("(");
            callStr = callStr.substr(0, callIdx);
            c2.argCalls.push_back(pair<string, int>(callStr, (*it)));
            //cout << callStr << endl;
        }

    }

    void gather_ftn_def();

    void pull_up_arg(){

        // 5. pull up arg of the parent
        // 6. check the call name in the parent class
        // 7. pull up the ftn interface which are not in the parent class
        // 8. ftn merge & arg type pull up

    }

    void merge_t4_clone_ftn(string fileName, CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2){

        // 1. compare two clone arg types
        vector< pair<string, string> >::iterator it1 = f1.ftnArgs.begin();
        vector< pair<string, string> >::iterator it2 = f2.ftnArgs.begin();
        int idx = 0;

        // 2. compare arg types and find the diffrent arg type
        for(; it1 != f1.ftnArgs.end() && it2 != f2.ftnArgs.end(); ++it1, ++it2){
            if((*it1).first != (*it2).first) break;
            idx++;
        }

        // preprocess and get ftn args
        string arg1 = f1.ftnArgs[idx].first;
        string arg2 = f2.ftnArgs[idx].first;
        string arg1Name = f1.ftnArgs[idx].second;
        string arg2Name = f2.ftnArgs[idx].second;
        get_class_hierarchy();

        string parent = classHierarchy.find(arg1)->second;

        if (chk_sibling(arg1, arg2)) {

            string parentType = classHierarchy.find(arg1)->second;
            string parentName = parentType;
            parentName.at(0) = tolower(parentName.at(0));
            // get new name of the parent object

            // 3. diff code
            // 4. get the diff part of the identical ftn calls
            // * 3/4 will be processed in one action
            vector<int> diffLine = get_diff(cloneDatas.front(), cloneDatas.back()); // TODO: refactor this?

            // find the ftn call of the 

            // 5. pull up arg of the parent
            // 5-1. chk parent class type before pull-up
            int pDefLine; // parent class def line
            class_type ct = get_class_type(parent, pDefLine);
            // 5-2. chk diff line obj calls. get obj calls and chk if parent class has those ftns.
            fetch_arg_calls(c1, c2, arg1Name, arg2Name, diffLine);

            // 6. check the call name in the parent class
            

            // 7. pull up the ftn interface which are not in the parent class
            // 8. ftn merge & arg type pull up
            pull_up_arg();

        }

    }




/*
 * ====================================================
 * ============= MAIN REFACTOR FUNCTIONS ==============
 * ====================================================
 */

void em_type1n2(){
    
    CloneData c1, c2;
    c1 = cloneDatas.front();
    c2 = cloneDatas.back();

    FtnType f1, f2;
    parse_ftn_type(c1.cloneSnippet.front(), f1);
    parse_ftn_type(c2.cloneSnippet.front(), f2);

    merge_clone_ftn(c1.fileName, c1, c2, f1, f2); // TODO: need to refactor?

}

void em_type3(){

    pair<int, int> p = get_common_part(cloneDatas.front(), cloneDatas.back());
    tempCodeLine = p.second - p.first + 1;
    trim_code(p.first, p.second);

    for(int i=0; i<tempCodeLine; i++){
        tempClone.push_back(cloneDatas.front().cloneSnippet.at(i + p.first - 1));
    }

    patch_code(cloneDatas.front().fileName);

}

void em_type4(){

    // 1. get ftn type of two clone snippets
    CloneData c1, c2;
    c1 = cloneDatas.front();
    c2 = cloneDatas.back();

    FtnType f1, f2;
    parse_ftn_type(c1.cloneSnippet.front(), f1);
    parse_ftn_type(c2.cloneSnippet.front(), f2);

    // 2. check clone ftn arg are sibling 
    merge_t4_clone_ftn(c1.fileName, c1, c2, f1, f2);

    // 3. diff code

    // 4. get the diff part of the identical ftn calls

    // 5. pull up arg of the parent

    // 6. check the call name in the parent class

    // 7. pull up the ftn interface which are not in the parent class

    // 8. ftn merge & arg type pull up

}

void refactor(clone_type ct){

    switch(ct) {
        case T1: 
        case T2:
            em_type1n2();
            break;

        case T3:
            em_type3();
            break;

        case T4:
            em_type4();
            break;
    }
    
}





/*
 * ====================================================
 * ================= TEST FUNCTIONS ===================
 * ====================================================
 */

void test_print(){

    // test printer to check clone data read
    cout << "Number of clone pair : " << n << endl;

    int count = 1;
    for(vector<CloneData>::iterator it = cloneDatas.begin(); it!=cloneDatas.end(); ++it){
        cout << "Clone #" << count++ << " : " << it->fileName << "\t" << it->from << "\t" << it->to << endl;
        cout << "Clone fragment line : " << it->cloneSize << "\n=== Clone fragment ===\n";
        for(vector<string>::iterator cit = it->cloneSnippet.begin(); cit!=it->cloneSnippet.end(); ++cit){
            cout << cit->c_str() << endl;
        }
    }

}

void print_caller(CloneData &cd){

    cout << "Number of callers : " << cd.callers.size() << endl;
    for(int i=0; i<cd.callers.size(); i++){
        cout << "Caller at : " << cd.callers[i].fileName << endl;
        cout << "Caller in : " << cd.callers[i].callerObjectName << "." << cd.callers[i].callerObjectFtnName << "()\n";
        cout << "Ftn called args : " << cd.callers[i].originalFtnName << "(";
        if(cd.callers[i].argNum == 0) cout << ")";
        for(int j=0; j<cd.callers[i].argNum; j++){
            cout << cd.callers[i].callArgs[j];
            if(j==cd.callers[i].argNum-1) cout << ")";
            else cout << ", ";
        }
        cout << "\nCalled line num : " << cd.callers[i].lineNum << endl;
    }

}

void print_code(vector<string> code){
    for(vector<string>::iterator it = code.begin(); it != code.end(); ++it){
        cout << (*it) << endl;
    }
}

void print_ftn_type(FtnType &f){
    cout << " ===== Function type ===== " << endl;
    for(int p=0; p<f.keywords.size(); p++){
        cout << f.keywords[p] << " ";
    }
    cout << f.ftnName << " : ";
    if (f.ftnArgs.size() > 0) {
        cout << "( ";
        for(int i=0; i<f.ftnArgs.size(); i++){
            if(i == f.ftnArgs.size()-1) {
                cout << f.ftnArgs.at(i).second << " : " << f.ftnArgs.at(i).first << " ) -> " << f.returnType << endl << endl;
            } else {
                cout << f.ftnArgs.at(i).second << " : " << f.ftnArgs.at(i).first << " * ";
            }
        }
    } else {
        cout << "void -> " << f.returnType << endl << endl;
    }
}

void print_arg_calls(CloneData &cd){
    
    cout << "# of arg calls : " << cd.argCalls.size() << endl;
    vector< pair<string, int> >::iterator it = cd.argCalls.begin();
    for(; it!=cd.argCalls.end(); ++it){
        cout << (*it).first << " at line #" << (*it).second << endl;
    }

}



/*
 * ====================================================
 * ================= MAIN FUNCTION ====================
 * ====================================================
 */

int main(int argc, char** argv){

    // USAGE :  ./autorefactor CLONEDATA
    if (argc < 2) {
        cerr << "Usage : " << argv[0] << " ALARMFILE" << endl;
        return 1;
    }

    read_file(argv[1]); // 1. reads input data

    string filename = "/home/yang/Sources/AutoRefactor/toyex/t4/HelloWorld.java";
    string a, b, c;
    fetchClassHierarchy(filename, a, b, c);
    cout << a << " " << b << " " << c << endl;

    printPtree(filename);
    dumpPtree(filename);

    refactor(T4); // 2. refactor the code according to the clone datas
    //print_code(tempClone);

    return 0;

} 