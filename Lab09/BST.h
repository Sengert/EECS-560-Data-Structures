/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 04
*
* Binary search tree (BST) with tree traversals:
*       Building a binary search tree from an input data file, the tree contains
*       multiple min/max functions and traversals
*******************************************************************************/
#ifndef BST_H
#define BST_H

struct Node{
        Node* parentNode;
        Node* rightSubNode;
        Node* leftSubNode;
        int value;
        bool isRoot;
};

class BST{
public:
        BST();
        ~BST();

        Node* root;

        void Insert(int x);
        void Delete(int x);
        void DeleteMin(Node* curNode);
        void DeleteMax(Node* curNode);
        Node* FindMin(Node* curNode);
        Node* FindMax(Node* curNode);
        void Preorder(Node* curNode);
        void Inorder(Node* curNode);
        void Postorder(Node* curNode);

private:
        void InsRecurse(int x, Node* subNode, Node* parent);


};

#endif
