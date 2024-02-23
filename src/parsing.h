#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include "AVL.h"
using namespace std;


bool validName(string& name) {
    for (int i = 0; i < name.length(); i++) {
        if (!(isalpha(name[i]) || isspace(name[i]))) return false;
    }
    return true;
}

bool validID(string& id) {
    if (id.length() != 8) return false;
    for (int i = 0; i < id.length(); i++) {
        if (!isdigit(id[i])) return false;
    }
    return true;
}

vector<string> getInputs(int numLines) {
    vector<string> allCMD;
    for (int i = 0; i <= numLines; i++) {
        string lineCMD;
        getline(cin, lineCMD);
        allCMD.push_back(lineCMD);
    }
    allCMD.erase(allCMD.begin());

    return allCMD;
}

void doFunctions(string lineCMD, AVL& myAVL) {

    string name;
    string ID;
    int idNum;
    auto pos = lineCMD.find_first_of(' ');
    string function = lineCMD.substr(0, pos);
    lineCMD = lineCMD.substr(pos + 1); // everything after the space is kept

    if (function == "insert") {

        lineCMD = lineCMD.substr(1); // remove first quote
        pos = lineCMD.find_first_of('\"'); // finds second quote

        name = lineCMD.substr(0, pos);
        //cout << "Name: " << name << "\n";

        lineCMD = lineCMD.substr(1);
        ID = lineCMD.substr(pos + 1);
        if (validID(ID) && validName(name)){ 
            idNum = stoi(ID);
            myAVL.insert(name, idNum);
            cout << "successful\n";
        }
        else cout << "unsuccessful\n";
        //cout << "ID: " << idNum << "\n";
        //cout << "ROOT: " << myAVL.getRoot()->getUFid() << "\n";

        }
    else if (function == "remove") {
        // FIXME: SHOULD PROBABLY VALIDATE ID
        if (validID(lineCMD)) {
            myAVL.removeID(stoi(lineCMD));
        }
        //cout << "ROOT2: " << myAVL.getRoot()->getUFid() << "\n";
    }
    else if (function == "removeInorder") {
        myAVL.removeInOrder(stoi(lineCMD));
    }
    else if (function == "search") {
        //search "shikha patel"
        // search 123884
        pos = lineCMD.find_first_of('\"');

        if (pos == string::npos) {
            // FIXME: CHECK IF IT IS A NUMBER
            cout << "SEARCH BY NUMBER\n";
            if (validID(lineCMD)) myAVL.searchID(stoi(lineCMD));
        }
        else {
            lineCMD = lineCMD.substr(pos + 1); // remove first quote
            pos = lineCMD.find_first_of('\"'); // finds second quote
            name = lineCMD.substr(0, pos);
            if (validName(name)) myAVL.searchName(name);
        }
    }
    else if (function == "printPreorder") {
        myAVL.printPreorder(myAVL.getRoot());
        myAVL.printOrder();
    }
    else if (function == "printInorder") {
        myAVL.printInorder(myAVL.getRoot());
        myAVL.printOrder();
    }
    else if (function == "printPostorder") {
        myAVL.printPostorder(myAVL.getRoot());
        myAVL.printOrder();
    }
    else if (function == "printLevelCount") {
        myAVL.printLevelCount(myAVL.getRoot());
    }
    else cout << "unsuccessful";

}