/*
 * Methods used for giving refactoring guides
 * These methods are used for simple analysis to get refactoring decisions
 * Implemented by jmyang <jmyang@ropas.snu.ac.kr>
 */

#include "include/ptree.h"
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

map<string,int> name2id;
map<int,string> id2name;

int yyparse();

extern Tree *root;

void id_init();

// method for finding class label. works only on fetching class names
void fetchClassHierarchy(string &file_name, string &classname, string &parent_classname, string &parent_intername){

  ParseTree* pt = parseFile(file_name.c_str());
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << file_name << endl;
    return;
  }

  // method for finding class label. works only on fetching class names
  string find = pt->getRoot()->findNode("class", classname, parent_classname, parent_intername);

}

void printPtree(string &fileName){

  id_init();

  ParseTree* pt = parseFile(fileName.c_str());
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }

  pt->getRoot()->print();
  pt->getRoot()->printTok();

}

void dumpPtree(string &fileName){

  id_init();

  ParseTree* pt = parseFile(fileName.c_str());
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }

  pt->outputParseTree2Dot(fileName.c_str(), false);

}

string getClassKeyword(string &file_name, string &class_type){

  ParseTree* pt = parseFile(file_name.c_str());
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << file_name << endl;
    return "";
  }

  string find = pt->getRoot()->findCnode("class", class_type);

}