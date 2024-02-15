#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Validate Input (ID 8 digits, Name no special char)
// Check class hierachy and access with TA


// Node Class
class Node {
    private:
        // Values like ID, name, and height
        int UFid;
        string name;

        // Children pointers
        Node* left;
        Node* right;
    public:
        // Constructors
        Node() : UFid(0), name(""), left(nullptr), right(nullptr) {}
        Node(int x, string studentName) : UFid(x), name(studentName), left(nullptr), right(nullptr) {}
        Node(int x, string studentName, Node* left, Node* right) : UFid(x), name(studentName), left(left), right(right) {}
        
        // Get Helper Functions
        int getUFid();
        string getName();
        Node* getLeft();
        Node* getRight();

        // Set Helper Functions
        void setLeft(Node* childLeft);
        void setRight(Node* childRight);
};


class AVLTree : private Node {
    private:
        Node* root;
        int nodeCount;

        
        Node* setRoot(Node* root);
        int getNodeCount();

        int findBalanceFactor(Node* root);

        Node* rotateLeft(Node* tempNode);
        Node* rotateRight(Node* tempNode);
        Node* rotateRightLeft(Node* tempNode);
        Node* rotateLeftRight(Node* tempNode);

        Node* balanceTree(int ID);

    public:
        AVLTree() : root(nullptr), nodeCount(0) {};
        Node* getRoot();
        int findHeight(Node* root);
        Node* insert(Node* root, int id, string name);
        void printLevelOrder(Node* root);
        void printLevel(Node* root, int level);

};