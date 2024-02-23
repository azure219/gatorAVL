#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "AVL.h"
using namespace std;

// Root Functions (Getter and Setter)
Node* AVL::getRoot() {

    return root;
}
Node* AVL::setRoot(Node* rootNode) {

    root = rootNode;
    return root;
}

// Miscellaneous Helper Functions
int AVL::returnCount() {

    return nodeCount;
}

int AVL::returnBalanceFactor(Node* root) {

    if (root == nullptr) {
     
        return 0;
    }

    return ( returnHeight(root->getLeft()) - returnHeight(root->getRight()) );
}

int AVL::returnHeight(Node* root) {

    if (root == nullptr) {
    
        return 0;
    }

    int left = returnHeight(root->getLeft());
    int right = returnHeight(root->getRight());

    return ( 1 + max(left, right) );
}

Node* AVL::inOrderSuccessor(Node* root) {
    
    Node* temp = root;

    while (temp->getLeft() != nullptr) {
    
        temp = temp->getLeft();
    }

    return temp;
}

// Rotate Helper Functions
Node* AVL::rotateLeft(Node* temp) {

    Node* newParent = temp->getRight();
    Node* grandchild = newParent->getLeft();
    newParent->setLeft(temp);
    temp->setRight(grandchild);

    return newParent;
}
Node* AVL::rotateRight(Node* temp) {

    Node* newParent = temp->getLeft();
    Node* grandchild = newParent->getRight();
    newParent->setRight(temp);
    temp->setLeft(grandchild);

    return newParent;
}
Node* AVL::rotateRightLeft(Node* temp) {

    //cout << "right left\n";
    temp->setRight(rotateRight(temp->getRight()));

    return rotateLeft(temp);
}
Node* AVL::rotateLeftRight(Node* temp) {

    //cout << "right left\n";
    temp->setLeft(rotateLeft(temp->getLeft()));

    return rotateRight(temp);
}

// <----------- Primary Helper Functions ----------->

// Insert Function Helper
Node* AVL::insertHelper(Node* root, string name, int id) {
    
    // Step 1: Insert Node

    // If a null root is reached, insert a new node at root, increase nodeCount
    if (root == nullptr) {

        nodeCount++;
        return new Node(id, name);
    }
    // Else, the root is not null and a new node must be inserted either left or right of the root
    else if (id < root->getUFid()) { // Insert left

        root->setLeft(insertHelper(root->getLeft(), name, id));
    }
    else if (id > root->getUFid()) { // Insert right

        root->setRight(insertHelper(root->getRight(), name, id));
    }
    else {
  
        cout << "unsuccessful\n";
    }

    // Step 2: Rebalance Tree

    // Find balance factor of new tree
    int balFactor = returnBalanceFactor(root);

    if (balFactor > 1) { // Tree is left heavy, perform appropriate rotations

        if (id < root->getLeft()->getUFid()) {

            return rotateRight(root);
        }
        else {

            return rotateLeftRight(root);
        }
    }
    if (balFactor < -1) { // Tree is right heavy, perform appropriate rotations

        if (id > root->getRight()->getUFid()) {
         
            return rotateLeft(root);
        }
        else {
            
            return rotateRightLeft(root);
        }
    }

    return root;
}

// Remove ID Function Helper
Node* AVL::removeHelper(Node* node, int id) {

    if (node == nullptr) {

        cout << "unsuccessful\n";
        return nullptr;
    }
    else if (id > node->getUFid()) { // ID of Node to remove is greater than current node's ID, move right

        node->setRight(removeHelper(node->getRight(), id));
    }
    else if (id < node->getUFid()) { // ID of Node to remove is less than current node's ID, move left

        node->setLeft(removeHelper(node->getLeft(), id));
    }
    else { // At Node to remove
        // If Node Has No Children
        if (node->getLeft() == nullptr && node->getRight() == nullptr) {

            //nodeCount--;
            delete node;
            cout << "successful\n";
            node = nullptr;

            return node;
        }
        // Else If Node Has Right Children Only
        else if(node->getLeft() == nullptr) {

            Node* temp = node;
            node = node->getRight();
            //nodeCount--;
            delete temp;
            cout << "successful\n";

            return node;
        }
        // Else If Node Has Left Children Only
        else if(root->getRight() == nullptr) {

            Node* temp = node;
            node = node->getLeft();
            //nodeCount--;
            delete temp;
            cout << "successful\n";

            return node;
        }
        // Else Node Has Two Children
        else {

            // Copy the In Order Successor
            Node* temp = inOrderSuccessor(node->getRight());
            node->setID(temp->getUFid());
            node->setName(temp->getName());
            node->setRight(removeHelper(node->getRight(), node->getUFid()));

            return node;
        }
    }

    return node;
}

// Remove In Order Function Helper
Node* AVL::removeInorderHelper(Node* node, int& n) {
    //cout << n << "\n";
    if (n < 0) {

        return root;
    }
    if (node) {

        removeInorderHelper(node->getLeft(), n);
        n--;

        if (n == 0) {
            // cout << node->getName() << node->getUFid() << "\n";
            nodeCount--;
            //when there is no children
            removeHelper(root, node->getUFid());
        }
        
        removeInorderHelper(node->getRight(), n);
    }

    return root;
}

// Search ID Helper Function
Node* AVL::searchIDHelper(Node* root, int id) {

    Node* temp = nullptr;

    if (nodeCount == 0) {

        return nullptr;
    }

    if (root == nullptr) {

        return temp;
    }
    else if (root->getUFid() == id) {

        temp = root;
        return temp;
    }
    else if (root->getUFid() > id) {
    
        temp = searchIDHelper(root->getLeft(), id);
    }
    else if (root->getUFid() < id) {
    
        temp = searchIDHelper(root->getRight(), id);
    }

    return temp;
}

// Search Name Helper Function
void AVL::searchNameHelper(Node* root, string name, vector<int>& ids) {

    if (!root) return;

    if (root->getName() == name) {

        ids.push_back(root->getUFid());
    }

    searchNameHelper(root->getLeft(), name, ids);
    searchNameHelper(root->getRight(), name, ids);
}

// <----------- Primary Functions ----------->

    // Insert Function
void AVL::insert(string name, int id) {

    setRoot(insertHelper(root, name, id));
}

    // Remove ID Function
void AVL::removeID(int id) {
    nodeCount--;
    root = removeHelper(root, id);
}

    // Remove In Order Function
void AVL::removeInOrder(int n){
    
    if (n > nodeCount) {

        cout << "unsuccessful\n";
    }
    else {

        n++;
        Node* temp = removeInorderHelper(root, n);
        if (temp == nullptr) cout << " NOT WORKING";
        //else cout << "successful\n";
    }
    //cout << removeInOrderHelper(root, n)->getName();
  
    //cout << "CORRECT NODE RETURNED: " << temp->getName() << "\n";
    //removeIDHelper(root, temp->getUFid());
   
}

    // Search ID Function
void AVL::searchID(int id) {

    Node* name = searchIDHelper(root, id);

    if (name == nullptr) {

        cout << "unsuccessful\n";
        return;
    }
    else {
        
        cout << name->getName() << "\n";
    }
}

    // Search Name Function
void AVL::searchName(string name) {

    vector<int> ids;
    searchNameHelper(root, name, ids);

    if (ids.empty()) {

        cout << "unsuccessful\n";
        return;
    }

    for (int i = 0; i < ids.size(); i++) {

        // changed to .at(i)
        cout << ids[i] << "\n";
    }
}

// <----------- Helper Print Functions ----------->

void AVL::printLevelOrder(Node* root) { 

    int h = returnHeight(root);

    for (int level = 1; level <= h; level++) {

        cout << "level: " << level << '\n';
        printLevel(root, level);
    }
}

void AVL::printLevel(Node* root, int level) {

    if (root == nullptr) {

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

    // Node Print Function
void AVL::printNode(Node* node, const string& comma) {

    cout << node->getName() << comma;
}

    // Vector Print Function
void AVL::printOrder() {

    for (int i = 0; i < allNodes.size() - 1; i++) {

        printNode(allNodes.at(i), ", ");
    }

    printNode(allNodes.at(allNodes.size() - 1), "");

    cout << "\n";
    allNodes.clear();
}

// <----------- Helper Print Functions ----------->

void AVL::printInorder(Node* root) {

    if (!root) {

        return;
    }

    printInorder(root->getLeft());

    allNodes.push_back(root);

    printInorder(root->getRight());
}
void AVL::printPreorder(Node* root) {

    if (!root) {

        return;
    }

    allNodes.push_back(root);

    printPreorder(root->getLeft());
    printPreorder(root->getRight());
}
void AVL::printPostorder(Node* root) {

    if (!root) {
    
        return;
    }

    printPostorder(root->getLeft());
    printPostorder(root->getRight());

    allNodes.push_back(root);
}
void AVL::printLevelCount(Node* root) {

    cout << returnHeight(root) << "\n";
}

// AVL Tree Deconstructor Function
Node* AVL::deleteAVL(Node* node) {

    if (!node) {

        return nullptr;
    }
    else {

        deleteAVL(node->getLeft());
        deleteAVL(node->getRight());

        delete node;
    }

    return nullptr;
}

// AVL Tree Deconstructor
AVL::~AVL() { 

    root = deleteAVL(root);
}