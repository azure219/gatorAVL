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

Node* Node::getLeft() {
    return left;
}
Node* Node::getRight() {
    return right;
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
    if (!root) return 0;
    int left = findHeight(root->getLeft());
    int right = findHeight(root->getRight());
    return 1 + max(left, right);
}

int AVLTree::findBalanceFactor(Node* root) {
    if (!root) return 0;
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
    Node* newChild = tempNode->getRight();
    newChild = rotateRight(newChild);
    return rotateLeft(tempNode);
}
Node* AVLTree::rotateLeftRight(Node* tempNode) {
    Node* newChild = tempNode->getLeft();
    newChild = rotateLeft(newChild);
    return rotateRight(tempNode);
}

Node* AVLTree::balanceTree(int id) {
    int balNum = findBalanceFactor(root);
    if (balNum > 1 && id < root->getLeft()->getUFid()) {
        return rotateRight(root);
    }
    else if (balNum < -1 && id > root->getRight()->getUFid()) {
        return rotateLeft(root);
    }
    else if (balNum > 1 && id > root->getLeft()->getUFid()) {
        return rotateLeftRight(root);
    }
    else if (balNum < -1 && id < root->getRight()->getUFid()) {
        return rotateRightLeft(root);
    }
    return getRoot();
}

Node* AVLTree::insert(Node* root, int id, string name) {
    if (root == nullptr) {
        nodeCount++;
        return setRoot(new Node(id, name));
    }
    else if (root->getUFid() > id) {
        //cout << "left";
        root->setLeft(insert(root->getLeft(), id, name));
        //setRoot(balanceTree(id));
    }
    else if(root->getUFid() < id) {
        //cout << "right";
        root->setRight(insert(root->getRight(), id, name));
        //setRoot(balanceTree(id));
    }
    else cout << "unsuccesfull\n";
    return root;
}

void AVLTree::printLevelOrder(Node* root) {

    int h = findHeight(root);
    for (int level = 1; level <= h; level++) {
        printLevel(root, level);
    }
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