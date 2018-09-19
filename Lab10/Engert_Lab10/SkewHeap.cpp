/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 10
*
* LeftistHeap and SkewHeap:
*       Building a LeftistHeap and SkewHeap based on tree implementation,
*       Heaps contain Insertion, Concate, DeleteMin, and multiple traversals
*******************************************************************************/

#include "SkewHeap.h"

using namespace std;

SkewHeap::SkewHeap(){
        root = nullptr;
        cout << "A SkewHeap has been created." << endl;
        return;
}

SkewHeap::~SkewHeap(){
        //Delete the root until heap is empty
        while(root != nullptr){
                DeleteMin();
        }
        return;
}

void SkewHeap::BuildHeap(){
        //////////////////////////////////////////////////////////////////
        //Is this function necessary? We would probably need to pass in an
        //array containing the integers from the data file, then iterate
        //through that calling Insert for each one.
        //////////////////////////////////////////////////////////////////
        cout << "Implement me!" << endl;
        return;
}

//Creates a new node and Concates it to the existing structure
void SkewHeap::Insert(int x){
        //Create a new node containing the value passed in
        LNode* insNode = new LNode;
        insNode->value = x;
        //Concate the new node with the previous heap structure
        root = Concate(root, insNode);
        cout << "Inserted " << x << " into the SkewHeap.\n";

        return;
}

//Deletes the root, then Concates the two remaining subtrees
void SkewHeap::DeleteMin(){
        //If the tree is empty do nothing
        if(root == nullptr){
                cout << "The SkewHeap is already empty." << endl;
        }
        else{
                LNode* temp = root;//Keep a reference to old root
                //Set new root
                root = Concate(root->lChild, root->rChild);
                //Delete old root
                cout << "[DEBUG]Deleting : " << temp->value << endl;
                delete temp;
                temp = nullptr;
        }
        return;
}

//Prints the root, which contains the smallest value in the heap
//O(1)
void SkewHeap::FindMin(){
        if(root == nullptr){
                cout << "The SkewHeap is empty." << endl;
        }
        else{
                cout << "The minimum value contained in the SkewHeap is : " << root->value << endl;
        }
        return;
}

//Recursive function that will merge two skew heaps, can also be used
//with insertion, just treat the new node as a heap.
LNode* SkewHeap::Concate(LNode* H1, LNode* H2){
        //Concate() was written following the algorithm from the in
        //class lecture notes
        //First case, one of the heaps are empty
        if(H1 == nullptr){
                return(H2);
        }
        else if(H2 == nullptr){
                return(H1);
        }
        else{
                if(H1->value > H2->value){
                        //Swap
                        LNode* temp = H1;
                        H1 = H2;
                        H2 = temp;
                        temp = nullptr;
                }

                if(H1->lChild == nullptr){
                        H1->lChild = H2;
                }
                else{
                        //Recurse
                        H1->rChild = Concate(H1->rChild, H2);
                        //Swap
                        LNode* temp = H1->lChild;
                        H1->lChild = H1->rChild;
                        H1->rChild = temp;
                        temp = nullptr;
                }
                return(H1);
        }
}

void SkewHeap::Preorder(LNode* curNode){
        if(root == nullptr){
                cout << "The SkewHeap is empty.\n";
                return;
        }
        //Hit the end of a subtree
        if(curNode == nullptr){
                return;
        }
        //Print the value of the Node
        cout << curNode->value << " ";
        //Traverse left subtree
        Preorder(curNode->lChild);
        //Traverse right subtree
        Preorder(curNode->rChild);

        return;
}

void SkewHeap::Inorder(LNode* curNode){
        if(root == nullptr){
                cout << "The SkewHeap is empty.\n";
                return;
        }
        //Hit the end of a subtree
        if(curNode == nullptr){
                return;
        }
        //Traverse left subtree
        Inorder(curNode->lChild);
        //Print the value of the Node
        cout << curNode->value << " ";
        //Traverse right subtree
        Inorder(curNode->rChild);

        return;
}

void SkewHeap::Levelorder(){
        if(root == nullptr){
                cout << "The skew heap is empty." << endl;
        }
        else{
                LNode* temp = root;
                LeftistQueue* mySkewQ = new LeftistQueue();

                mySkewQ->insert(root);

                while(!mySkewQ->isEmpty()){
                        temp = mySkewQ->peek();
                        mySkewQ->dequeue();
                        cout << temp->value << " ";

                        if(temp->lChild != nullptr){
                                mySkewQ->insert(temp->lChild);
                        }
                        if(temp->rChild != nullptr){
                                mySkewQ->insert(temp->rChild);
                        }
                }
                delete mySkewQ;
        }
}

LNode* SkewHeap::GetRoot(){
        return(root);
}
