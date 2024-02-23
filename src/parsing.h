#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include "AVL.h"

using namespace std;


bool nameValidator(string& name) {

    for (int i = 0; i < name.length(); i++) {

        if (!(isalpha(name[i]) || isspace(name[i]))) {

            return false;
        }
    }

    return true;
}

bool idValidator(string& id) {

    if (id.length() != 8) {
        return false;
    }

    for (int i = 0; i < id.length(); i++) {

        if (!isdigit(id[i])) {

            return false;
        }
    }

    return true;
}

int functionAssigner(string function) {

    if (function == "insert") {
        return 1;
    }
    else if (function == "remove") {
        return 2;
    }
    else if (function == "removeInorder") {
        return 3;
    }
    else if (function == "search") {
        return 4;
    }
    else if (function == "printPreorder") {
       return 5;
    }
    else if (function == "printInorder") {
        return 6;
    }
    else if (function == "printPostorder") {
        return 7;
    }
    else if (function == "printLevelCount") {
       return 8;
    }
    else {
        return 0;
    }

}

vector<string> getCommands(int numLines) {

    vector<string> commandsVector;

    for (int i = 0; i <= numLines; i++) {

        string lineCommand;
        getline(cin, lineCommand);

        commandsVector.push_back(lineCommand);
    }

    commandsVector.erase(commandsVector.begin());

    return commandsVector;
}

void parser(string lineCommand, AVL& myAVL) {

    string name;
    string id;
    int idNum;

    auto position = lineCommand.find_first_of(' ');

    int functionID = functionAssigner(lineCommand.substr(0, position));

    lineCommand = lineCommand.substr(position + 1);

    switch (functionID) {

        case 1:

            lineCommand = lineCommand.substr(1); 
            position = lineCommand.find_first_of('\"');

            name = lineCommand.substr(0, position);

            lineCommand = lineCommand.substr(1);
            id = lineCommand.substr(position + 1);

            if (nameValidator(name) && idValidator(id)) { 

                idNum = stoi(id);
                myAVL.insert(name, idNum);

                cout << "successful\n";
            }
            else {

                cout << "unsuccessful\n";
            }
            break;

        case 2:

            if (idValidator(lineCommand)) {

                myAVL.removeID(stoi(lineCommand));
            }
            break;
        case 3:

            myAVL.removeInOrder(stoi(lineCommand));

            break;
        case 4:

            position = lineCommand.find_first_of('\"');

            if (position == string::npos) {

                if (idValidator(lineCommand)) {
                    myAVL.searchID(stoi(lineCommand));
                }
            }
            else {

                lineCommand = lineCommand.substr(position + 1); 
                position = lineCommand.find_first_of('\"');

                name = lineCommand.substr(0, position);

                if (nameValidator(name)) {

                    myAVL.searchName(name);
                }

            }
            break;    
        case 5:

            myAVL.printPreorder(myAVL.getRoot());
            myAVL.printOrder();

            break;
        case 6:

            myAVL.printInorder(myAVL.getRoot());
            myAVL.printOrder();

            break;
        case 7:

            myAVL.printPostorder(myAVL.getRoot());
            myAVL.printOrder();

            break;
        case 8:

            myAVL.printLevelCount(myAVL.getRoot());

            break;
        default:

            cout << "unsuccessful";
            break;
    }

}