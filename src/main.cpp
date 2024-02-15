#include <iostream>
#include "AVLTree.h"

using namespace std;

int main() {

	// cout << "Hello AVL!\n";

	AVLTree tree;   // Create a Tree object
	tree.insert(nullptr, 3, "jay ");
	tree.insert(tree.getRoot(), 2, "shikha ");
	tree.insert(tree.getRoot(), 1, "seher ");
	cout << "ROOT: " << tree.getRoot()->getName() << tree.getRoot()->getUFid() << '\n';
	cout << "HEIGHT: " << tree.findHeight(tree.getRoot()) << "\n";
	tree.printLevelOrder(tree.getRoot());
	//cout << tree.getRoot()->getLeft()->getUFid() << " " << tree.getRoot()->getLeft()->getUFid();

	return 0;
}
