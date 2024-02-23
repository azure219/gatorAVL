#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Node Class
class Node {

    private:

        // Node values
        int UFid;
        string name;
        
        // Children (or left and right) pointers
        Node* left;
        Node* right;

    public:

        // Node constructors
        Node() : UFid(0), name(""), left(nullptr), right(nullptr) {}
        Node(int x, string studentName) : UFid(x), name(studentName), left(nullptr), right(nullptr) {}

        // Getter Functions
        int getUFid() {

            return UFid;
        }
        string getName() {

            return name;
        }
        Node* getLeft() {

            return left;
        }
        Node* getRight() {

            return right;
        }

        // Setter Functions
        void setLeft(Node* childLeft) {

            left = childLeft;
        }
        void setRight(Node* childRight) {

            right = childRight;
        }
        void setID(int studentID) {

            UFid = studentID;
        }
        void setName(string studentName) {

            name = studentName;
        }

};

// AVL Tree Class derived from Node Class
class AVL : private Node {

    private:

        Node* root;
        int nodeCount;

        vector<Node*> allNodes;
        
        // Primary Helper Functions
        Node* rotateLeft(Node* temp);
        Node* rotateRight(Node* temp);
        Node* rotateRightLeft(Node* temp);
        Node* rotateLeftRight(Node* temp);

        Node* setRoot(Node* root);

        // Miscellaneous Helper Functions
        int returnCount();
        int returnBalanceFactor(Node* root);
        int returnHeight(Node* root);
        Node* inOrderSuccessor(Node* root);

        // Primary Helper Functions
        Node* insertHelper(Node* root, string name, int id);
        Node* removeHelper(Node* root, int id);
        Node* searchIDHelper(Node* root, int id);
        void searchNameHelper(Node* root, string name, vector<int>& ids);
        Node* removeInorderHelper(Node* root, int& n);

        // Print Helper Functions
        void printLevel(Node* root, int level);
        void printNode(Node* node, const string& comma);

    public:

        //int nodeCount;

        // AVL Tree Constructor
        AVL() : root(nullptr), nodeCount(0) {};
        Node* getRoot();

        void printLevelOrder(Node* root);
        void printOrder();
        
        // Primary Functions
        void insert(string name, int id);
        void removeID(int id);
        void removeInOrder (int n);
        void searchID(int id);
        void searchName(string name);
        void printInorder(Node* root);
        void printPreorder(Node* root);
        void printPostorder(Node* root);
        void printLevelCount(Node* root);

        // Destructors
        Node* deleteAVL(Node* node);
       ~AVL();

};