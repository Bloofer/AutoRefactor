#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "dtl/dtl/dtl.hpp"
using namespace std;

int n; // number of clone sites

// refactor data structures

// TODO: to impl read meaningful callers to patch
// struct type for caller datas
typedef struct{
    string filename;
    string callname;
    vector<string> callargs;
    int callsite;
}Caller;

// struct type for clone datas
typedef struct{
    string fileName;
    int from, to;
    vector<string> cloneSnippet;
    int cloneSize;
    // vector<Caller> callers; // TODO: maybe need to add caller datas?
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

// functions for type 1 & 2
void parse_ftn_type(string s, FtnType &ftype);
void preprocess(CloneData &c1, CloneData &c2);
void fetch_callers();
vector<int> get_diff(CloneData &c1, CloneData &c2);
bool int_vec_contains(vector<int> &iv, int i);
void merge_clone_ftn(string fileName, CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2);

// functions for type 3
pair<int, int> get_common_part();
void patch_code(string fileName); // replace code clone with new function
void trim_code(int p, int q);

// test functions
void test_print(); // test printer for check cloneDatas
void print_code();
void test_diff();
void print_ftn_type(FtnType &f);


/*
 * ====================================================
 * =============== FILE I/O FUNCTIONS =================
 * ====================================================
 */

// maybe replace with merging the code to refactor_guide?
void read_file(char* alarmFile){

    ifstream cfile(alarmFile);
    cfile >> n;

    CloneData temp_cd;

    for(int i=0; i<n; i++){
        cfile >> temp_cd.fileName >> temp_cd.from >> temp_cd.to;
        temp_cd.cloneSize = temp_cd.to - temp_cd.from + 1;

        ifstream ccode(temp_cd.fileName.c_str());
        int line = 1;
        string temp;
        while (line <= temp_cd.to) {
            getline(ccode, temp);
            if (line >= temp_cd.from) temp_cd.cloneSnippet.push_back(temp);
            line++; 
        }

        cloneDatas.push_back(temp_cd);
        temp_cd.fileName = "";
        temp_cd.from = temp_cd.to = temp_cd.cloneSize = 0;
        temp_cd.cloneSnippet.clear();
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

    if(str.find_first_not_of(' ') != std::string::npos) return false;
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


/*
 * ====================================================
 * ============ FUNCTIONS FOR TYPE 1 & 2 ==============
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

void fetch_callers(){
    // function for fetching caller datas
    // using data from the alarm file which are parsed from DOT file

    // 1. read in the caller data from the input file

    // 2. put caller data in Caller structure

    // 3. get the call site code line too. to use for caller patching
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

bool int_vec_contains(vector<int> &iv, int i){
    return ( find(iv.begin(), iv.end(), i) != iv.end() );
}

void merge_clone_ftn(string fileName, CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2){
    
    vector<int> diffLine = get_diff(cloneDatas.front(), cloneDatas.back()); // TODO: refactor this?
    // 1. insert procedure branches using if/else statements using flag.
    // use diffLine to get the diff lines
    int tabIdx = c1.cloneSnippet.front().find_first_not_of(" \t\r\n"); // this is for code formatting
    string tabStr = "";
    for(int i=0; i<tabIdx; i++){
        tabStr += ' ';
    }

    // 2. insert flag at the ftn decl.
    // use FtnType to not get new function name & arg name
    string ftnDecl = tabStr;
    for(int i=0; i<f1.keywords.size(); i++){
        ftnDecl += (f1.keywords[i] + " ");
    }

    string newFtnName = f1.ftnName + f2.ftnName;
    ftnDecl += (f1.returnType + " " + newFtnName + "(");
    for(int i=0; i<f1.ftnArgs.size(); i++){
        ftnDecl += f1.ftnArgs[i].first;
        ftnDecl += " ";
        ftnDecl += f1.ftnArgs[i].second;
        if (i != f1.ftnArgs.size()-1) ftnDecl += ", ";
    }
    ftnDecl += ") {"; // TODO: maybe need to refactor b.c. parenthesis not in first line?
    tempClone.push_back(ftnDecl);

    for(int i=1; i<c1.cloneSize; i++){
        if (!int_vec_contains(diffLine, i)) tempClone.push_back(c1.cloneSnippet[i]);
        else {
            tempClone.push_back(tabStr + "if(flag == 0)" + c1.cloneSnippet[i]);
            tempClone.push_back(tabStr + "else if(flag == 1)" + c2.cloneSnippet[i]);
        }
    }

    fetch_callers();
    // 3. fetch caller datas
    // 4. substitute caller function name with new one.

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






/*
 * ====================================================
 * ============= MAIN REFACTOR FUNCTIONS ==============
 * ====================================================
 */

void em_type1n2(){
    
    //preprocess(cloneDatas.front(), cloneDatas.back());
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
    
    refactor(T1); // 2. refactor the code according to the clone datas
    print_code(tempClone);

    return 0;

} 