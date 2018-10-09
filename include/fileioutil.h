#include <dirent.h>
#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

int read_dir_files(string dirName);
void fetchFname2CnameVec(string dirName, vector< pair<string, string> > &pairVec);