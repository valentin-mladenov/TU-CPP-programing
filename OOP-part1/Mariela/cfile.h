//
// Created by hudson on 9.4.2016 г..
//

#ifndef OOP_PART1_CFILE_H
#define OOP_PART1_CFILE_H

#include <string>

using namespace std;

class CFile {
    string fileName;
    string fileExtention;
  public:
    CFile(string file_name, string fileExtention);

    string getName();
    void setName(string fileName);

    string getExtention();
    void setExtention(string fileExtention);
};


#endif //OOP_PART1_CFILE_H
