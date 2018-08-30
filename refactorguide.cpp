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

typedef struct{
  int nodeId;
  bool isTerminal;
  string label; // empty if non-terminal
  int lineNo;   // empty if non-terminal
  int depth;    // depth of tree. same if siblings
}NodeData;

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

void getPtree(string &fileName, stringstream &ss){

  ParseTree* pt = parseFile(fileName.c_str());
  
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }

  string fname = "f";
  pt->getRoot()->getFtnSubtree(ss, fname);

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

int str2int(const char *s)
{
    int i;
    i = 0;
    while(*s >= '0' && *s <= '9')
    {
        i = i * 10 + (*s - '0');
        s++;
    }
    return i;
}

void print_node_vector(vector<NodeData> &ndVec){

  for(int i=0; i<ndVec.size(); i++){

    if(ndVec.at(i).isTerminal) {
      cout << "T [ nodeID : " << ' ' << " \tlabel : " << ndVec.at(i).label 
           << "\tlineNum : " << ndVec.at(i).lineNo << "\tdepth : " << ndVec.at(i).depth << " ]\n";
    } else {
      cout << "NT[ nodeID : " << ndVec.at(i).nodeId << " \tlabel : " << ' '
           << "\tlineNum : " << ' ' << "\tdepth : " << ndVec.at(i).depth << " ]\n";
    }

  }

}

void ss2NodeVec(vector<NodeData> &ndVec, stringstream &ss){

  string tok;
  int treeDepth = 0;

  while(ss >> tok){
    
    if (tok.at(0) == '[') {
      // if token is right tree parenthesis, increase depth
      treeDepth++;
    } else if (tok.at(0) == ']') {
      // if token is left tree parenthesis, decrease depth
      treeDepth--;
    } else if (tok.at(0) >= '0' && tok.at(0) <= '9') {
      // Non-terminal Node
      // if token is nodeID, create node object and push to vector
      NodeData ntNode;
      ntNode.nodeId = str2int(tok.c_str());
      ntNode.isTerminal = false;
      ntNode.label = ""; // leave it empty b.c. this data is not used for non-terminal node
      ntNode.lineNo = 0; // leave it zero b.c. this data is not used for non-terminal node
      ntNode.depth = treeDepth;
      ndVec.push_back(ntNode);
    } else if (tok.at(0) == '<') {
      // Terminal Node
      // if token is label, create node object and push to vector
      string tok1 = tok;

      if (tok.substr(0,2) == "<\"") {
        if (tok.substr(tok.size()-2) != "\">") {
          ss >> tok;
          tok1 += (" " + tok);
          while(tok.substr(tok.size()-2) != "\">") {
            ss >> tok;
            tok1 += (" " + tok);
          }
        }
      }
      string tok2;
      ss >> tok2; // parse second token to fetch line number

      NodeData tNode;
      tNode.nodeId = -1; // leave it negative one b.c. this data is not used for terminal node
      tNode.isTerminal = true;
      tNode.label = tok1.substr(1, tok1.size()-2);
      tNode.lineNo = str2int(tok2.substr(1).c_str());
      tNode.depth = treeDepth;
      ndVec.push_back(tNode);
    } else {
      // return error if found exceptional token in ss
      cerr << "Error : Abnormal token found in the string stream. Token : " << tok << endl;
      return;
    }

  }

}

void getFtnSubtree(string &fileName, string &ftnName){
  
  id_init();

  ParseTree* pt = parseFile(fileName.c_str());
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << fileName << endl;
    return;
  }
  
  stringstream ss;
  pt->getRoot()->getFtnSubtree(ss, ftnName);
  cout << ss.str() << endl << endl;

  vector<NodeData> ndVec;
  ss2NodeVec(ndVec, ss);
  print_node_vector(ndVec);

}

string getClassKeyword(string &file_name, string &class_type){

  ParseTree* pt = parseFile(file_name.c_str());
  if ( pt==NULL ) {
    cerr << "Error: no parse tree created for file: " << file_name << endl;
    return "";
  }

  string find = pt->getRoot()->findCnode("class", class_type);

}