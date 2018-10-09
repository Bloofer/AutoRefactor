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

bool mapFullPath(vector< pair<string, string> > &pairVec, string &path, string &cname, string &realPath){
// CallGraph에서 찾은 Path, Class name 가지고 Caller의 실제 Path 찾기
// CallGraph에서는 실제 Caller의 절대경로 위치를 알려주지 않기 때문에
// pairVec에서 실제 절대경로를 찾아 Caller 패치에 사용한다.

    for(int i=0; i<pairVec.size(); i++){
        if(pairVec.at(i).first.find(path) != string::npos){
        // pairVec에서 해당 path를 발견한 경우, 실제 path와 매핑해준다.
            if(pairVec.at(i).second.find(cname) != string::npos){
                realPath = pairVec.at(i).first;
                return true;
            }
        }
    }

    return false;
    // 아무것도 찾지 못한 경우 false 반환.

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
                fetchClassName(fname, cname);
                if(cname == "") {
                    cnt++;
                }
                pairVec.push_back(pair<string, string>(fname, cname));
            }
        }
        closedir (dir);
    } else {
        /* could not open directory */
        cerr << "could not open directory" << endl;
        return;
    }

}