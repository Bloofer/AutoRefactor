#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;

// global varibles for auto clone refactor
const int maximum_clone_line = 300;
int clone_code_line = 0; // maybe need more of these?
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
    string filename;
    int from, to;
    vector<Caller> callers;
}CloneData;
vector<CloneData> CloneDatas;

typedef enum {
    T1,
    T2,
    T3,
    T4
} clone_type;

// temporary variable to save the clone code snippets
string temp_clone[maximum_clone_line];

void read_file(); // reads input file including clone data
void refactor(clone_type ct); // the main function for auto refactoror

// method extraction for 4 types of code clones
void em_type1();
void em_type2();
void em_type3();
void em_type4();

// internal functions for extract_method()
void annotation_process(); // commentate the original code of the clone part
void method_insertion(); // insert function call into clone part
void extract_definition(); // extract function definition for the replaced clone parts

// test functions
void test_print(); // test printer for check CloneDatas
void test_print_clone_snippets();


/*
 * ====================================================
 * ============= REFACTOR SUB FUNCTIONS =============
 * ====================================================
 */

void annotation_process(){

    // nom nom ...
    // TODO: need to impl file write part

    ifstream ifile("test/ePrint.com.fasoo.util.FasooMessageParser.java");
    ofstream ofile("test/refactored_ePrint.com.fasoo.util.FasooMessageParser.java");

    string temp_str;
    int line_num = 0;

    while(getline(ifile, temp_str)){
        ++line_num;
        if((line_num >= CloneDatas.back().from) && (line_num <= CloneDatas.back().to)){
            ofile << "// ";
            temp_clone[clone_code_line++] = temp_str;
        }
        ofile << temp_str << endl;
    }

}

void method_insertion(){

    // nom nom ...

}

void extract_definition(){

    // nom nom ...

}





/*
 * ====================================================
 * =============== REFACTOR FUNCTIONS =================
 * ====================================================
 */

void em_type1(){

    annotation_process(); // 1. annotate the clone site. removing the clone
    method_insertion(); // 2. remove clone and insert method instead
    extract_definition(); // 3. extract common part of the clone and make it new definition

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
 * =============== FILE I/O FUNCTIONS =================
 * ====================================================
 */

// maybe replace with merging the code to refactor_guide?
void read_file(){

    // nom nom ...
    // writes data into Clonedatas

    ifstream cfile("test/test_clonedata.txt");
    cfile >> n;

    CloneData temp_cd;

    for(int i=0; i<n; i++){
        cfile >> temp_cd.filename >> temp_cd.from >> temp_cd.to;
        CloneDatas.push_back(temp_cd);
        temp_cd.filename = "";
        temp_cd.from = temp_cd.to = 0;
    }

}





/*
 * ====================================================
 * ================= TEST FUNCTIONS ===================
 * ====================================================
 */

void test_print(){

    // test printer to check clone data read
    cout << n << endl;

    for(vector<CloneData>::iterator it = CloneDatas.begin(); it!=CloneDatas.end(); ++it){
        cout << it->filename << "\t" << it->from << "\t" << it->to << endl;
    }

}

void test_print_clone_snippets(){

    for(int i = 0; i<clone_code_line; i++){
        cout << temp_clone[i] << endl;
    }

}





/*
 * ====================================================
 * ================= MAIN FUNCTION ====================
 * ====================================================
 */

int main(){

    // USAGE :  ./autorefactor CLONEDATA

    read_file(); // 1. reads input data
    //test_print();
    refactor(T1); // 2. refactor the code according to the clone datas

    //test_print_clone_snippets();

    return 0;

}