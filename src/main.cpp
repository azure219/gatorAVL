#include <iostream>
#include <vector>
#include "AVL.h"
#include "parsing.h"

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

// to run: g++ -std=c++14 main.cpp AVLTree.cpp && ./a.out

int main () {

	AVL tree;
	
	int commandsNumber;
	cin >> commandsNumber;

    vector<string> commandsList = getCommands(commandsNumber);

    for (int i = 0; i < commandsList.size(); i++) {

        parser(commandsList[i], tree);
    }

	return 0;
}