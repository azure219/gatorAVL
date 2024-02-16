#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "AVLTree.h"
using namespace std;


int Node::getUFid() {
    return UFid;
}

string Node::getName(){
    return name;
}

int Node::getHeight() {
    return height;
}

Node* Node::getLeft() {
    return left;
}
Node* Node::getRight() {
    return right;
}

void Node::setHeight(int num) {
    height = num;
}

void Node::setLeft(Node* childLeft) {
    left = childLeft;
}

void Node::setRight(Node* childRight) {
    right = childRight;
}



Node* AVLTree::getRoot() {
    return root;
}
Node* AVLTree::setRoot(Node* rootNode) {
    root = rootNode;
    return root;
}
int AVLTree::getNodeCount() {
    return nodeCount;
}

int AVLTree::findHeight(Node* root) {
    if (root == nullptr) return 0;
    int left = findHeight(root->getLeft());
    int right = findHeight(root->getRight());
    return 1 + max(left, right);
}

int AVLTree::findBalanceFactor(Node* root) {
    if (root == nullptr) return 0;
    return findHeight(root->getLeft()) - findHeight(root->getRight());
}

Node* AVLTree::rotateLeft(Node* tempNode) {
    Node* newParent = tempNode->getRight();
    Node* grandchild = newParent->getLeft();
    newParent->setLeft(tempNode);
    tempNode->setRight(grandchild);
    return newParent;
}

Node* AVLTree::rotateRight(Node* tempNode) {
    Node* newParent = tempNode->getLeft();
    Node* grandchild = newParent->getRight();
    newParent->setRight(tempNode);
    tempNode->setLeft(grandchild);
    return newParent;
}
Node* AVLTree::rotateRightLeft(Node* tempNode) {
    cout << "right left\n";
    tempNode->setRight(rotateRight(tempNode->getRight()));
    return rotateLeft(tempNode);
}
Node* AVLTree::rotateLeftRight(Node* tempNode) {
    tempNode->setLeft(rotateLeft(tempNode->getLeft()));
    return rotateRight(tempNode);
}

Node* AVLTree::balanceTree(int id) {
    int balFactor = findBalanceFactor(root);

    if (balFactor > 1) {
        if (id < root->getLeft()->getUFid()) return rotateRight(root);
        else return rotateLeftRight(root);
    }
    if (balFactor < -1) {
        if (id > root->getRight()->getUFid()) return rotateLeft(root);
        else return rotateRightLeft(root);
    }
    return root;
}

Node* AVLTree::insertHelper(Node* root, int id, string name) {
    if (root == nullptr) {
        nodeCount++;
        return new Node(id, name);
    }
    else if (root->getUFid() > id) {
        //cout << "left";
        root->setLeft(insertHelper(root->getLeft(), id, name));
        //cout << "helpme\n"; 
        //return balanceTree(id);
    }
    else if(root->getUFid() < id) {
        //cout << "right";
        root->setRight(insertHelper(root->getRight(), id, name));
        //cout << "help me\n";
        //return balanceTree(id);
    }
    else cout << "unsuccesfull\n";

    //balanceTree(id);

    int balFactor = findBalanceFactor(root);

    if (balFactor > 1) {
        if (id < root->getLeft()->getUFid()) return rotateRight(root);
        else return rotateLeftRight(root);
    }
    if (balFactor < -1) {
        if (id > root->getRight()->getUFid()) return rotateLeft(root);
        else return rotateRightLeft(root);
    }

    // Return head
    return root;
}

void AVLTree::insert(int id, string name) {
    setRoot(insertHelper(root, id, name));
}

void AVLTree::printLevelOrder(Node* root) {
    int h = findHeight(root);
    for (int level = 1; level <= h; level++) {
        printLevel(root, level);
    }
}

void AVLTree::printInorder(Node* root) {
    // if (!root) {
    //     cout << "-";
    // } 
    if (root) {
        printInorder(root->getLeft());
        cout << root->getUFid() << root->getName() << ", ";
        printInorder(root->getRight());
    }
}
void AVLTree::printPreorder(Node* root) {
    /*if (!root) {
        cout << "/";
    }*/
    if (root) {
        cout << root->getUFid() << root->getName() << ", ";
        printPreorder(root->getLeft());
        printPreorder(root->getRight());
    }
}
void AVLTree::printPostorder(Node* root) {
    // if (!root) {
    //     cout << "|";
    // } 
    if (root) {
        printPostorder(root->getLeft());
        printPostorder(root->getRight());
        cout << root->getUFid() << root->getName() << ", ";
    }
}
void AVLTree::printLevelCount(Node* root) {
    cout << findHeight(root);
}

void AVLTree::printLevel(Node* root, int level) {
    if (!root) {
        return;
    }
    if (level == 1) {
        cout << root->getName() << " " << root->getUFid() << "\n";
    }
    else if (level > 1) {
        printLevel(root->getLeft(), (level - 1));
        printLevel(root->getRight(), (level - 1));
    }
}