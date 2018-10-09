#include <dirent.h>
#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

int read_dir_files(string dirName);
bool mapFullPath(vector< pair<string, string> > &pairVec, string &path, string &cname, string &realPath);
void fetchFname2CnameVec(string dirName, vector< pair<string, string> > &pairVec);