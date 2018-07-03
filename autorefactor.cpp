#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "dtl/dtl/dtl.hpp"
using namespace std;

// global varibles for auto clone refactor
const int maxCloneLine = 300;
int n; // number of clone sites

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
void refactor(clone_type ct); // the main function for auto refactoror

// method extraction for 4 types of code clones
void em_type1();
void em_type2();
void em_type3();
void em_type4();

// diff two clone pair to get the common part
bool are_same(string s1, string s2);
pair<int, int> get_common_part();
bool only_spaces(string str);
void patch_code(string fileName); // replace code clone with new function
bool contains(string str, string word);
void trim_code(int p, int q);

// test functions
void test_print(); // test printer for check cloneDatas
void print_code();
void test_diff();





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

bool are_same(string s1, string s2){

    if(only_spaces(s1) && only_spaces(s2)) return true;
    else if(only_spaces(s1) || only_spaces(s2)) return false;

    dtl::Diff< char, string > strDiff(s1, s2);
    strDiff.compose();
    return (strDiff.getEditDistance() == 0);

}

bool only_spaces(string str){

    if(str.find_first_not_of(' ') != std::string::npos) return false;
    else return true;
    
}

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

bool contains(string str, string word){
    // checks if str contains word
    return (str.find(word) < str.size() && str.find(word) >= 0);

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
 * =============== REFACTOR FUNCTIONS =================
 * ====================================================
 */

void em_type1(){

    pair<int, int> p = get_common_part(cloneDatas.front(), cloneDatas.back());
    tempCodeLine = p.second - p.first + 1;
    trim_code(p.first, p.second);

    for(int i=0; i<tempCodeLine; i++){
        tempClone.push_back(cloneDatas.front().cloneSnippet.at(i + p.first - 1));
    }

    patch_code(cloneDatas.front().fileName);

}

void em_type2(){

}

void em_type3(){

}

void em_type4(){

}

void refactor(clone_type ct){

    switch(ct) {
        case T1:
            em_type1();
            break;

        case T2:
            em_type2();
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

void test_diff(){

    typedef char elem;
    typedef std::string sequence;
    sequence A(cloneDatas.front().cloneSnippet.back());
    sequence B(cloneDatas.back().cloneSnippet.back());
    dtl::Diff< elem, sequence > d(A, B);
    //d.onOnlyEditDistance();
    d.compose();
    
    // editDistance
    cout << "editDistance:" << d.getEditDistance() << endl;
    
    // Longest Common Subsequence
    vector< elem > lcs_v = d.getLcsVec();
    sequence       lcs_s(lcs_v.begin(), lcs_v.end());
    cout << "LCS:" << lcs_s << endl;
    
    // Shortest Edit Script
    cout << "SES" << endl;
    d.printSES();

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
    test_print();
    //get_common_part(cloneDatas.front(), cloneDatas.back());
    
    refactor(T1); // 2. refactor the code according to the clone datas
    print_code(patchCode);
    //patch_code();

    return 0;

} 