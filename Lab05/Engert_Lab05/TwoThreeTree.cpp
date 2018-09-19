/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 05
*
* Two-Three Trees with level order print:
*       Building a 2-3 tree from an input data file, the tree contains
*       multiple min/max functions and a level order print of the contents
*******************************************************************************/
#include "TwoThreeTree.h"
#include "LevelOrderQueue.h"
#include <iostream>

using namespace std;


TwoThreeTree::TwoThreeTree(){
        cout << "[DEBUG] A new 2-3 tree has been created!\n";
        root = nullptr;
}


TwoThreeTree::~TwoThreeTree(){
        //Destructor
        /*
        while(root != nullptr){
                DeleteMax();
        }
        */
}

void TwoThreeTree::Insert(int x){
        if(Find(x) != nullptr){
                cout << "This value is already in the 2-3 tree!\n";
                return;//Value is already in the tree
        }
        //Case : the tree is an empty tree
        if(root == nullptr){
                root = new TwoThreeNode;
                root->setValue(x);
        }
        //Case : there is 1 node in the entire tree and it is a leaf
        else if(!(root->getIsInterior())){
                //Check if the value to insert is smaller than root's current value
                if(x <= root->getValue()){
                        //Place x as the left leaf of root
                        TwoThreeNode* leftTemp = new TwoThreeNode;
                        root->setFirstChild(leftTemp);
                        leftTemp->setParent(root);
                        leftTemp->setValue(x);

                        //Place root's original key as the right leaf
                        TwoThreeNode* rightTemp = new TwoThreeNode;
                        root->setSecondChild(rightTemp);
                        rightTemp->setParent(root);
                        rightTemp->setValue(root->getValue());
                }
                else{
                        //New x's value is larger than root's key

                        //Place root's original key as the left leaf of root
                        TwoThreeNode* leftTemp = new TwoThreeNode;
                        root->setFirstChild(leftTemp);
                        leftTemp->setParent(root);
                        leftTemp->setValue(root->getValue());

                        //Place x as the right leaf of root
                        TwoThreeNode* rightTemp = new TwoThreeNode;
                        root->setSecondChild(rightTemp);
                        rightTemp->setParent(root);
                        rightTemp->setValue(x);
                }
                //Convert the root to an interior Node and update
                root->setIsInterior(true);
                UpdateNodes(root);
        }
        //Case : The root node is an interior node with 2 leaf children, insert the new x value
        //       and update the root node's variables
        else if(root->getFirstChild() != nullptr && root->getSecondChild() != nullptr && root->getThirdChild() == nullptr
                && !root->getFirstChild()->getIsInterior() && !root->getSecondChild()->getIsInterior()){
                TwoThreeNode* temp = new TwoThreeNode;
                temp->setValue(x);
                temp->setParent(root);

                //Relink root's children
                if(x < root->getFirstChild()->getValue()){
                        root->setThirdChild(root->getSecondChild());
                        root->setSecondChild(root->getFirstChild());
                        root->setFirstChild(temp);
                }
                else if(x < root->getSecondChild()->getValue()){
                        root->setThirdChild(root->getSecondChild());
                        root->setSecondChild(temp);
                }
                else{
                        root->setThirdChild(temp);
                }
                //Update root's minSecond and minThird
                UpdateNodes(root);
        }
        //Case : The root node is an interior node with 3 leaf children, rearrange the tree
        //       and create 2 new interior nodes
        else if(root->getThirdChild() != nullptr && !root->getSecondChild()->getIsInterior()){
                root = ConvertLeafFourNode(root, x);
                UpdateNodes(root);
        }
        else{
                //Root is no longer the only interior node, resort to SecondaryInsert
                //Locate the parent node of where x is supposed to be inserted to
                TwoThreeNode* tempParent = LocationTraversal(root, x)->getParent();
                SecondaryInsert(CreateLeaf(tempParent, x), tempParent);
                UpdateNodes(root);
        }

        return;
}

//A helper function to insert, this handles the cases beyond inserting to
//a root node that contains only leaves
void TwoThreeTree::SecondaryInsert(TwoThreeNode* curNode, TwoThreeNode* parent){
        //Case : The parent node that was passed in has two children.
        if(parent->getThirdChild() == nullptr){
                //Arrange the 3 leaves in the correct order.
                if(curNode->getValue() < parent->getFirstChild()->getValue()){
                        //New leaf is the new smallest value, shift old children over
                        parent->setThirdChild(parent->getSecondChild());
                        parent->setSecondChild(parent->getFirstChild());
                        parent->setFirstChild(curNode);
                }
                else if(curNode->getValue() < parent->getSecondChild()->getValue()){
                        //New leaf is the second smallest value, shift the older child over
                        parent->setThirdChild(parent->getSecondChild());
                        parent->setSecondChild(curNode);
                }
                else{
                        //New leaf is the new largest value, insert it as the third child
                        parent->setThirdChild(curNode);
                }
                curNode->setParent(parent);
        }
        //Case : The parent node tht was passed in has 3 children, now we must split
        else{

                TwoThreeNode* tempNode = ConvertLeafFourNode(parent, curNode->getValue());
                tempNode->setParent(parent->getParent());

                //Relink the parent's child to the new tempNode
                if(parent->getParent()->getFirstChild() == parent){
                        parent->getParent()->setFirstChild(tempNode);
                }
                else if(parent->getParent()->getSecondChild() == parent){
                        parent->getParent()->setSecondChild(tempNode);
                }
                else if(parent->getParent()->getThirdChild() == parent){
                        parent->getParent()->setThirdChild(tempNode);
                }

                //Rearrange the tree now the there are height differences on the leaves
                RearrangeTree(tempNode, tempNode->getParent());

        }


        return;
}

void TwoThreeTree::RearrangeTree(TwoThreeNode* newNode, TwoThreeNode* oldParent){
        //Adjust the old root node by moving it down to be a child of newNode
        //And set the newNode to the overall root
        if(oldParent->getThirdChild() == nullptr && oldParent == root){
                //There is only 1 other sibling, make the sibling a child of the new node
                newNode->setThirdChild(oldParent->getSecondChild());
                oldParent->getSecondChild()->setParent(newNode);
                oldParent = nullptr;
                newNode->setParent(nullptr);
                root = newNode;
        }
        //Adjust the old root node to be a sibling of newNode, both under a newly created parent
        else if(oldParent == root){
                TwoThreeNode* newRoot = new TwoThreeNode;
                newRoot->setIsInterior(true);

                //There are 2 other siblings, shift the 2 siblings over and
                //make the old root a sibling of the new node, create a new root interior
                if(oldParent->getFirstChild() == newNode){
                        //Shift both left
                        oldParent->setFirstChild(oldParent->getSecondChild());
                        oldParent->setSecondChild(oldParent->getThirdChild());
                        oldParent->setThirdChild(nullptr);

                        newRoot->setFirstChild(newNode);
                        newRoot->setSecondChild(oldParent);
                }
                else if(oldParent->getSecondChild() == newNode){
                        //Shift the thirdChild left
                        oldParent->setSecondChild(oldParent->getThirdChild());
                        oldParent->setThirdChild(nullptr);

                        //TODO: Case that the middle tree is the one being split
                        //Make one of its siblings a child of the newly split node
                        //and make its parent a sibling of itself and create a new
                        //interiorNode as the parent of the two.
                }
                else{
                        //No shifting needs to be done
                        oldParent->setThirdChild(nullptr);

                        newRoot->setFirstChild(oldParent);
                        newRoot->setSecondChild(newNode);
                }

                root = newRoot;
                newRoot->setParent(nullptr);
        }
        //TODO: Handle cases where oldParent isn't the root, now need to recurse RearrangeTree()

}

//recursively updates the minSecond and minThird values of all interior nodes starting
//with the node passed in as the root
void TwoThreeTree::UpdateNodes(TwoThreeNode* curNode){
        //If node exists and isn't a leaf
        if(curNode != nullptr && curNode->getIsInterior()){
                //Now recursively update all sub Trees
                UpdateNodes(curNode->getFirstChild());
                if(curNode->getSecondChild() != nullptr){
                        UpdateNodes(curNode->getSecondChild());
                        curNode->setMinSecond(FindMin(curNode->getSecondChild())->getValue());
                        curNode->setValue(FindMin(curNode->getSecondChild())->getValue());//TODO:May not be working correctly
                }
                else{
                        //No second child found
                        curNode->setMinSecond(-1);
                }
                //Update minThirds
                if(curNode->getThirdChild() != nullptr){
                        UpdateNodes(curNode->getThirdChild());
                        curNode->setMinThird(FindMin(curNode->getThirdChild())->getValue());
                }
                else{
                        //No third child found
                        curNode->setMinThird(-1);
                }
        }
}

//Converts a node that would become a four node after insertion to a
//a node containing 2 new interior nodes which hold the four values in
//their respective subtrees, returns a new parent of these two new nodes
TwoThreeNode* TwoThreeTree::ConvertLeafFourNode(TwoThreeNode* oldParent, int val){
        LevelOrderQueue* convertQ = new LevelOrderQueue;
        TwoThreeNode* newParent = new TwoThreeNode();
        TwoThreeNode* newFirstinteriorNode = new TwoThreeNode();
        TwoThreeNode* newSecondInteriorNode = new TwoThreeNode();

        newParent->setFirstChild(newFirstinteriorNode);
        newParent->setSecondChild(newSecondInteriorNode);

        newSecondInteriorNode->setValue(val);

        //Set up the queue of all the leaves
        if(val < oldParent->getFirstChild()->getValue()){
                //Val is the new smallest value
                convertQ->insert(newSecondInteriorNode);
                convertQ->insert(oldParent->getFirstChild());
                convertQ->insert(oldParent->getSecondChild());
                convertQ->insert(oldParent->getThirdChild());

        }
        else if(val > oldParent->getFirstChild()->getValue() && val < oldParent->getSecondChild()->getValue()){
                //Val is the second smallest value
                convertQ->insert(oldParent->getFirstChild());
                convertQ->insert(newSecondInteriorNode);
                convertQ->insert(oldParent->getSecondChild());
                convertQ->insert(oldParent->getThirdChild());
        }
        else if(val > oldParent->getSecondChild()->getValue() && val < oldParent->getThirdChild()->getValue()){
                //Val is the third smallest value
                convertQ->insert(oldParent->getFirstChild());
                convertQ->insert(oldParent->getSecondChild());
                convertQ->insert(newSecondInteriorNode);
                convertQ->insert(oldParent->getThirdChild());
        }
        else{
                //Val is the new largest value
                convertQ->insert(oldParent->getFirstChild());
                convertQ->insert(oldParent->getSecondChild());
                convertQ->insert(oldParent->getThirdChild());
                convertQ->insert(newSecondInteriorNode);
        }
        //Set new nodes' parent
        newFirstinteriorNode->setParent(newParent);
        newSecondInteriorNode->setParent(newParent);

        //Set children on the new left interior node
        newFirstinteriorNode->setFirstChild(CreateLeaf(newFirstinteriorNode, convertQ->peek()->getValue()));
        convertQ->dequeue();
        newFirstinteriorNode->setSecondChild(CreateLeaf(newFirstinteriorNode, convertQ->peek()->getValue()));
        convertQ->dequeue();
        newFirstinteriorNode->setIsInterior(true);

        //Set children on the new right interior node
        newSecondInteriorNode->setFirstChild(CreateLeaf(newSecondInteriorNode, convertQ->peek()->getValue()));
        convertQ->dequeue();
        newSecondInteriorNode->setSecondChild(CreateLeaf(newSecondInteriorNode, convertQ->peek()->getValue()));
        convertQ->dequeue();
        newSecondInteriorNode->setIsInterior(true);


        delete convertQ;
        convertQ = nullptr;
        newFirstinteriorNode = nullptr;
        newSecondInteriorNode = nullptr;

        newParent->setIsInterior(true);
        return(newParent);
}

//Used as a helper for initilizing new leaf nodes
//Creates a new leaf node containing the value x and links
//it to the parent, RETURNS a pointer to this new leaf
TwoThreeNode* TwoThreeTree::CreateLeaf(TwoThreeNode* parent, int x){
        TwoThreeNode* temp = new TwoThreeNode;
        temp->setValue(x);
        temp->setParent(parent);

        return(temp);
}

//Returns the leaf node of where an a value x should become a child of
//the parent of the returned node
TwoThreeNode* TwoThreeTree::LocationTraversal(TwoThreeNode* startNode, int val){
        if(root == nullptr){
                //Tree is is empty
                return(nullptr);
        }
        if(!startNode->getIsInterior()){
                //The starting node is a leaf, return it and compare from there
                return(startNode);
        }
        else if(startNode->getMinThird() <= val && startNode->getMinThird() != -1){
                //Traverse down the third child
                return(LocationTraversal(startNode->getThirdChild(), val));
        }
        else if(startNode->getMinSecond() <= val && startNode->getMinSecond() != -1){
                //Traverse down the second child
                return(LocationTraversal(startNode->getSecondChild(), val));
        }
        else{
                //Traverse down the first child
                return(LocationTraversal(startNode->getFirstChild(), val));
        }
}

//Deletes the leaf node containing the value x, prints a message
//if the value was not in the tree
void TwoThreeTree::Delete(int x){
        TwoThreeNode* delNode = Find(x);

        if(delNode == nullptr){
                cout << "This value doesn't exist in the tree.\n";
                return;
        }
        TwoThreeNode* delNodeParent = delNode->getParent();

        //The node we want to delete has 2 other siblings
        if(delNodeParent->getThirdChild() != nullptr){
                //Find the position delNode is in relative to its siblings
                if(delNodeParent->getFirstChild() == delNode){
                        //Node to delete is the first leaf
                        delNodeParent->setFirstChild(delNodeParent->getSecondChild());
                        delNodeParent->setSecondChild(delNodeParent->getThirdChild());
                        delNodeParent->setThirdChild(nullptr);
                }
                else if(delNodeParent->getSecondChild() == delNode){
                        //Node to delete is the second leaf
                        delNodeParent->setSecondChild(delNodeParent->getThirdChild());
                        delNodeParent->setThirdChild(nullptr);
                }
                else{
                        //Node to delete is the third leaf
                        delNodeParent->setThirdChild(nullptr);
                }


                delete delNode;
                delNode = nullptr;
                delNodeParent = nullptr;
                UpdateNodes(root);
                return;
        }
        //The node we want to delete has 1 other sibling and we must rearrange the tree
        //when we delete the node
        else{
                DeleteTwoSibling(delNode);
                UpdateNodes(root);
        }

        return;
}

//Used with deletion in the case that there are only 2 children
//of the interior node that a node is being deleted from, uses a Priority
//Queue to rearrange the leaves after deletion.
void TwoThreeTree::DeleteTwoSibling(TwoThreeNode* del){
        cout << "[DEBUG]Delete not performed.\n";
        cout << "[DEBUG]Fix implementation of deleting when there is only 1 other sibling.\n";
        cout << "[DEBUG]See DeleteTwoSibling() function to see commented implementation.";
        //******************************************************************
        //TODO:I ran out of time to finish/fix the seg fault I was getting from
        //deleting a leaf that had only 1 other sibling, but this is the way
        //I was going about it below.
        //******************************************************************
/*
        //Fill a priority queue
        if(root == nullptr){
                cout << "The tree is empty.\n";
                return;
        }
        LevelOrderQueue* tempQ = new LevelOrderQueue();
        TwoThreeNode* tempNode;
        TwoThreeNode* oldRoot = root;
        tempQ->insert(oldRoot);

        root = nullptr;
        while(!tempQ->isEmpty()){
                tempNode = tempQ->peek();

                if(!tempNode->getIsInterior()){
                        //Node is a leaf compare it to delNode
                        if(del->getValue() != tempNode->getValue()){
                                //Reinsert to the new root
                                Insert(tempNode->getValue());
                        }
                        else{
                                //Dequeue this value
                        }
                }

                //Traversals
                if(tempNode->getFirstChild() != nullptr){
                        tempQ->insert(tempNode->getFirstChild());
                }
                if(tempNode->getSecondChild() != nullptr){
                        tempQ->insert(tempNode->getSecondChild());
                }
                if(tempNode->getThirdChild() != nullptr){
                        tempQ->insert(tempNode->getThirdChild());
                }

                tempQ->dequeue();
        }
        cout << endl;
        delete tempQ;
        tempQ = nullptr;
*/
        return;


}
//Deletes the leaf node containing teh minimum value
void TwoThreeTree::DeleteMin(){
        TwoThreeNode* delNode = FindMin(root);

        if(delNode == nullptr){
                cout << "The tree is empty.\n";
        }
        else{
                Delete(delNode->getValue());
        }
        delNode = nullptr;
        return;
}

//Deletes the leaf node containing the maximum value
void TwoThreeTree::DeleteMax(){
        TwoThreeNode* delNode = FindMax(root);

        if(delNode == nullptr){
                cout << "The tree is empty.\n";
        }
        else{
                Delete(delNode->getValue());
        }
        delNode = nullptr;
        return;
}

//Finds a leaf node containing the value x and returns it, Returns
//a nullptr if the value is not in the tree
TwoThreeNode* TwoThreeTree::Find(int x){
        TwoThreeNode* foundNode = LocationTraversal(root, x);

        if(foundNode == nullptr){
                //Tree is empty
                return(nullptr);
        }
        if(foundNode->getValue() == x){
                return(foundNode);
        }
        else{
                return(nullptr);
        }
}

//Finds the TwoThreeNode leaf node containing the minimum value
//And returns a pointer to it
TwoThreeNode* TwoThreeTree::FindMin(TwoThreeNode* curNode){
        //If tree is is empty
        if(root == nullptr){
                return(nullptr);
        }

        if(!curNode->getIsInterior()){
                //This node is a leaf and is the leftmost node
                return(curNode);
        }
        else{
                //Travserse
                FindMin(curNode->getFirstChild());
        }
}

//Finds the TwoThreeNode leaf node containing the maximum value
//And returns a pointer to it
TwoThreeNode* TwoThreeTree::FindMax(TwoThreeNode* curNode){
        //If tree is is empty
        if(root == nullptr){
                return(nullptr);
        }

        if(!curNode->getIsInterior()){
                //This node is a leaf and is the rightmost node
                return(curNode);
        }
        else{
                if(curNode->getThirdChild() != nullptr){
                        //Traverse third child if there is one
                        FindMax(curNode->getThirdChild());
                }
                else{
                        //if not, then traverse the second child
                        FindMax(curNode->getSecondChild());
                }
        }
}

//Prints the 2-3 tree in level order using a Priority queue
void TwoThreeTree::LevelOrder(){
        if(root == nullptr){
                cout << "The tree is empty.\n";
                return;
        }
        LevelOrderQueue* tempQ = new LevelOrderQueue();
        TwoThreeNode* tempNode;
        tempQ->insert(root);

        while(!tempQ->isEmpty()){
                tempNode = tempQ->peek();
                if(!tempNode->getIsInterior()){
                        //Node is a leaf
                        cout << tempNode->getValue() << " ";
                }
                else{
                        //DEBUG print for interior nodes
                        //cout << tempNode->getMinSecond() << " " << tempNode->getMinThird() << " ";
                }

                //Traversals
                if(tempNode->getFirstChild() != nullptr){
                        tempQ->insert(tempNode->getFirstChild());
                }
                if(tempNode->getSecondChild() != nullptr){
                        tempQ->insert(tempNode->getSecondChild());
                }
                if(tempNode->getThirdChild() != nullptr){
                        tempQ->insert(tempNode->getThirdChild());
                }

                tempQ->dequeue();
        }
        cout << endl;
        delete tempQ;
        tempQ = nullptr;

        return;
}
