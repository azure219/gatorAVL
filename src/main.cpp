#include <iostream>
#include "AVLTree.h"

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

// to run: g++ -std=c++14 main.cpp AVLTree.cpp && ./a.out

int main() {

	AVLTree tree;   // Create a Tree object
	tree.insert(1, "allen");
	tree.insert(3, "jay");
	tree.insert(9, "meghana");
	tree.insert(2, "kyle");
	tree.insert(5, "shikha");
	tree.insert(4, "seher");
	tree.insert(8, "vraj");
	tree.insert(-1, "yeleeya");
	//cout << tree.findBalanceFactor(tree.getRoot());
	//cout << "ROOT: " << tree.getRoot()->getName() << tree.getRoot()->getUFid() << '\n';
	//cout << "HEIGHT: " << tree.findHeight(tree.getRoot()) << "\n";
	tree.printLevelOrder(tree.getRoot());
	// cout << "\n";
	// tree.printInorder(tree.getRoot());
	// cout << "\n";
	// tree.printPreorder(tree.getRoot());
	// cout << "\n";
	// tree.printPostorder(tree.getRoot());
	// cout << "\n";
	// tree.printLevelCount(tree.getRoot());
	
	return 0;
}