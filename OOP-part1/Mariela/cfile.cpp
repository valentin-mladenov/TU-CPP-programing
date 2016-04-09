//
// Created by hudson on 9.4.2016 г..
//

#include "cfile.h"


CFile::CFile(string fileName, string fileExtention) {
    this->setName(fileName);
    this->setExtention(fileExtention);
}

void CFile::setExtention(string fileExtention) {
    this->fileExtention = fileExtention;
}

void CFile::setName(string fileName) {
    this->fileName = fileName;
}

string CFile::getName() {
    return this->fileName;
}

string CFile::getExtention() {
    return this->fileExtention;
}




