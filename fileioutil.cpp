#include <dirent.h>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int read_dir_files(string dirName){

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

