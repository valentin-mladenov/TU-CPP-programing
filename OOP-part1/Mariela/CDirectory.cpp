//
// Created by hudson on 9.4.2016 г..
//

#include <algorithm>
#include "CDirectory.h"

CDirectory::CDirectory(string data){
    vector<string> dirAndFiles;
    vector<string> files;

    dirAndFiles = this->split(data, "\n");

    this->setDirName(dirAndFiles[0]);

    files = this->split(dirAndFiles[1], " ");

    for (int i = 0; i < files.size(); i += 2) {
        CFile* currentFile = new CFile(files[i], files[i + 1]);

        this->AddFile(currentFile);
    }

    delete(files, dirAndFiles);
}

string CDirectory::getDirName() {
    return this->dirName;
}

void CDirectory::setDirName(string dirName) {
    this->dirName = dirName;
}

vector<CFile*> CDirectory::getAllFiles() {
    return this->files;
}

void CDirectory::AddFile(CFile* fileData) {
    this->files.push_back(fileData);
}

vector<string> CDirectory::split(string toSplit, string delimiter) {
    vector<string> result;
    string::size_type i = 0;
    string::size_type j = toSplit.find(delimiter);

    while (j != string::npos) {
        result.push_back(toSplit.substr(i, j-i));
        i = ++j;
        j = toSplit.find(delimiter, j);

        if (j == string::npos)
            result.push_back(toSplit.substr(i, toSplit.length()));
    }

    return result;
}

int CDirectory::getHowManyByName(string name) {
    int count = 0;

    for (int i = 0; i < this->files.size(); ++i) {
        if (this->files[i]->getName() == name){
            count++;
        }
    }

    return count;
}

string CDirectory::removeAllDuplicateNames() {
    vector<string> filenames;
    vector<CFile> files;

    for (int i = 0; i < this->files.size(); ++i) {
        bool find = false;
        for (int j = 0; j < filenames.size(); ++j) {
            if (this->files[i]->getName() == filenames[j]) {
                find = true;
                break;
            }
        }

        if (find){
            continue;
        }

        filenames.push_back(this->files[i]->getName());
        files.push_back(this->files[i]);
    }

    this->files.clear();
    this->files = files;
    delete(filenames, files);

    return "Done";
}




