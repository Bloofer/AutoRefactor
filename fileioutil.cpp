#include <dirent.h>
#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "include/ptree.h"
#include "include/treeutil.h"
#include "treeTra/token-tree-map.h"
using namespace std;

int read_dir_files(string dirName){
// directory file read test function

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(dirName.c_str())) != NULL) {
    /* print all the files and directories within directory */
    while ((ent = readdir (dir)) != NULL) {
        cout << ent->d_name << endl;
    }
    closedir (dir);
    } else {
    /* could not open directory */
    cerr << "could not open directory" << endl;
    return EXIT_FAILURE;
    }

}

void fetchFname2CnameVec(string dirName, vector< pair<string, string> > &pairVec){
// 디렉토리 이름받아서 디렉토리 내 .java 파일들 파싱, [fname, cname] 벡터 생성
// T2 Caller 패치시 사용.
// TODO: 일단은 하나의 디렉토리에 모아놓고 실험 후 추후 확장하기(recursive하게 디렉토리 찾아서)
// pair vec of [ full path - class name ]

    int cnt = 0;

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(dirName.c_str())) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            string fname = ent->d_name;
            if(fname.find(".java") != string::npos) {
                // if file format is .java, parse file and get class name
                if(dirName.at(dirName.size()-1) != '/') dirName += '/';
                fname = dirName + fname;
                string cname, pcname, piname;
                fetchClassHierarchy(fname, cname, pcname, piname);
                // cout << fname << " | " << cname << endl;
                if(cname == "") cnt++;
                pairVec.push_back(pair<string, string>(fname, cname));
            }
        }
        closedir (dir);
    } else {
        /* could not open directory */
        cerr << "could not open directory" << endl;
        return;
    }

    cout << "Missed : " << cnt << endl;

}