//
// Created by hudson on 9.4.2016 г..
//

#ifndef OOP_PART1_CDIRECTORY_H
#define OOP_PART1_CDIRECTORY_H

#include <string>
#include <vector>
#include "cfile.h"

using namespace std;


class CDirectory {
    string dirName;
    vector<CFile*> files;

public:
    CDirectory(string data);

    string getDirName();
    void setDirName(string dirName);

    vector<CFile*> getAllFiles();
    void AddFile(CFile* fileData);

    vector<string> split(string toSplit, string delimiter);

    int getHowManyByName (string name);

    string removeAllDuplicateNames ();
};


#endif //OOP_PART1_CDIRECTORY_H
