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
        int height;

        // Children pointers
        Node* left;
        Node* right;
    public:
        // Constructors
        Node() : UFid(0), name(""), height(1), left(nullptr), right(nullptr) {}
        Node(int x, string studentName) : UFid(x), height(1), name(studentName), left(nullptr), right(nullptr) {}
        Node(int x, string studentName, int num, Node* leftChild, Node* rightChild) : UFid(x), name(studentName), height(num), left(leftChild), right(rightChild) {}
        
        // Get Helper Functions
        int getUFid();
        string getName();
        int getHeight();
        Node* getLeft();
        Node* getRight();

        // Set Helper Functions
        void setHeight(int num);
        void setLeft(Node* childLeft);
        void setRight(Node* childRight);
};


class AVLTree : private Node {
    private:
        Node* root;
        int nodeCount;
        
        Node* setRoot(Node* root);
        int getNodeCount();

        Node* rotateLeft(Node* tempNode);
        Node* rotateRight(Node* tempNode);
        Node* rotateRightLeft(Node* tempNode);
        Node* rotateLeftRight(Node* tempNode);

        Node* balanceTree(int ID);

        Node* insertHelper(Node* root, int id, string name);

    public:

        int findBalanceFactor(Node* root);
        AVLTree() : root(nullptr), nodeCount(0) {};
        Node* getRoot();
        int findHeight(Node* root);
        void insert(int id, string name);

        void printLevelOrder(Node* root);
        void printLevel(Node* root, int level);

        void printInorder(Node* root);
        void printPreorder(Node* root);
        void printPostorder(Node* root);
        void printLevelCount(Node* root);

};