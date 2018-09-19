/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 05
*
* Two-Three Trees with level order print:
*       Building a 2-3 tree from an input data file, the tree contains
*       multiple min/max functions and a level order print of the contents
*******************************************************************************/
#ifndef TWOTHREETREE_H
#define TWOTHREETREE_H
#include "TwoThreeNode.h"
#include "LevelOrderQueue.h"

class TwoThreeTree{
public:
        TwoThreeTree();
        ~TwoThreeTree();
        
        //Root node of the TwoThreeTree
        TwoThreeNode* root;

        //Pass in an int to the tree, if the int doesn't exist in a node within
        //the tree, a new node is created and inserted into the tree
        void Insert(int x);

        //A helper function for insert that handles the cases of creating a
        //new node when the leaves of the root node are also interior nodes,
        //Pass in a newly created node and an interior node that is the parent of
        //the newly created node.
        void SecondaryInsert(TwoThreeNode* curNode, TwoThreeNode* parent);

        //Pass in a newly created interior node and its parent, it then rearranges
        //the tree keeping all the leaves at the same height and creates a new
        //interior root node if needed.
        void RearrangeTree(TwoThreeNode* newNode, TwoThreeNode* oldParent);

        //Pass in an int, deletes a leaf node containing the value equal to the
        //passed int if it exists.
        void Delete(int x);

        //Pass in a leaf node containing the int value to delete, handles cases
        //when the leaf to be deleted has only 1 other sibling causing the tree
        //to need to be rebalanced. Rebalancing is done by reinserting leftover
        //nodes with a priority queue.
        void DeleteTwoSibling(TwoThreeNode* del);

        //Deletes the leaf node containing the minimum value of the tree
        void DeleteMin();

        //Deletes the leaf node containing the maximum value of the tree
        void DeleteMax();

        //Recursive function, pass in an interior node to start traversing
        //and an int to find which leaf's spot the int should be in. Returns
        //a pointer to the leaf at that spot.
        TwoThreeNode* LocationTraversal(TwoThreeNode* startNode, int val);

        //Pass in an interior node with 3 children and an int, creates a new leaf
        //containing that value of the passed int. Then creates a new parent with
        //2 new interior nodes. The first and second children of each new interior node
        //is populated with a priority queue.
        TwoThreeNode* ConvertLeafFourNode(TwoThreeNode* oldParent, int val);

        //Pass a pointer to an interior node and an int, initializes a new leaf
        //as a child of the passed parent and the new leaf contains a value equal
        //to the passed int
        TwoThreeNode* CreateLeaf(TwoThreeNode* parent, int x);

        //Pass a pointer of the TwoThreeNode currently being looked at, usually starting
        //with root. Recursively traverses the tree updating all interior nodes'
        //minSecond, minThird, and values.
        void UpdateNodes(TwoThreeNode* curNode);

        //Pass in a TwoThreeNode pointer of the starting node, usually the root.
        //Then recursively traverse down the left side of the tree until a leaf
        //is reached. Return a pointer to this leaf, which contains the minimum
        TwoThreeNode* FindMin(TwoThreeNode* curNode);

        //Pass in a TwoThreeNode pointer of the starting node, usually the root.
        //Then recursively traverse down the right side of the tree until a leaf
        //is reached. Return a pointer to this leaf, which contains the minimum
        TwoThreeNode* FindMax(TwoThreeNode* curNode);

        //Pass an int to find a node containing a value equal to the int,
        //returns a node to the leaf containing this value, returns a nullptr
        //if no node contains the value.
        TwoThreeNode* Find(int x);

        //Recursively traverses the tree in LevelOrder storing the nodes in a priority
        //queue, the queue is printed as standard output
        void LevelOrder();

private:


};

#endif
