/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 04
*
* Binary search tree (BST) with tree traversals:
*       Building a binary search tree from an input data file, the tree contains
*       multiple min/max functions and traversals
*******************************************************************************/
#include "BST.h"
#include <iostream>

using namespace std;


BST::BST(){
        //cout << "[DEBUG] A new binary search tree has been created!\n";
        root = nullptr;
}


BST::~BST(){
        while(root != nullptr){
                DeleteMax(root);
        }
}

void BST::Insert(int x){
        //Check if the tree is empty
        if(root == nullptr){
                root = new Node;
                root->parentNode = nullptr;
                root->leftSubNode = nullptr;
                root->rightSubNode = nullptr;

                root->value = x;
                //cout << "[DEBUG] " << x << " has been inserted as the BST's root value.\n";
                return;
        }
        else if(x < root->value){
                //Call insert for root's left subtree
                InsRecurse(x, root->leftSubNode, root);
        }
        else{
                //Call insert for root's right subtree
                InsRecurse(x, root->rightSubNode, root);
        }


        return;
}

//Helper function for Insert
void BST::InsRecurse(int x, Node* subNode, Node* parent){
        if(subNode == nullptr){
                //This slot is empty,create a new node and insert
                subNode = new Node;
                subNode->value = x;
                subNode->parentNode = parent;
/*
                cout << "[DEBUG]" << x << " has been inserted to the ";
                if(subNode->parentNode->value > x){
                        subNode->parentNode->leftSubNode = subNode;
                        cout << "left of " << subNode->parentNode->value << endl;
                }else{
                        subNode->parentNode->rightSubNode = subNode;
                        cout << "right of " << subNode->parentNode->value << endl;
                }
*/
                subNode->leftSubNode = nullptr;
                subNode->rightSubNode = nullptr;
                //Node has been created
        }
        else if(x < subNode->value){
                //Call insert for root's left subtree
                InsRecurse(x, subNode->leftSubNode, subNode);
        }
        else{
                InsRecurse(x, subNode->rightSubNode, subNode);
        }
        return;
}

void BST::Delete(int x){
        if(root == nullptr){
                cout << "BST is empty\n";
                return;
        }
        //Check if the root is the only value and it is equal to x
        if(root->leftSubNode == nullptr && root->rightSubNode == nullptr && root->value == x){
                delete root;
                root = nullptr;
                //cout << x << " has been deleted\n";
                return;
        }

        //Search for a node that contains a value equal to x
        Node* temp = root;
        while(temp != nullptr){
                //X matches the value of this Node
                if(x == temp->value){
                        break;
                }
                //Traverse left
                if(x < temp->value){
                        temp = temp->leftSubNode;
                }
                //Traverse right
                else{
                        temp = temp->rightSubNode;
                }

                //If temp reaches nullptr, value is not in the BST
                if(temp == nullptr){
                        //cout << x << " is not found in the BST.\n";
                        return;
                }
        }
        //If we made it past the while loop that means temp is pointing to a
        //node that contains a value equal to x and we need to delete it.

        //Case 1: Node is a leaf
        if(temp->leftSubNode == nullptr && temp->rightSubNode == nullptr){
                if(temp->value < temp->parentNode->value){
                        //temp is a left leaf
                        temp->parentNode->leftSubNode = nullptr;
                        delete temp;
                        temp = nullptr;
                        //cout << x << " has been deleted\n";
                        return;
                }
                else{
                        //temp is a right leaf
                        temp->parentNode->rightSubNode = nullptr;
                        delete temp;
                        temp = nullptr;
                        //cout << x << " has been deleted\n";
                        return;
                }
        }
        //Case 2: Node has 1 child
        if(temp->leftSubNode != nullptr && temp->rightSubNode == nullptr){
                //Node has a left only child
                if(temp->value < temp->parentNode->value){
                        //Relink the tree
                        temp->parentNode->leftSubNode = temp->leftSubNode;
                }
                else{
                        //Relink the tree
                        temp->parentNode->rightSubNode = temp->leftSubNode;
                }
                temp->leftSubNode->parentNode = temp->parentNode;
                delete temp;
                temp = nullptr;
                //cout << x << " has been deleted\n";
                return;
        }
        else if(temp->rightSubNode != nullptr && temp->leftSubNode == nullptr){
                //Node has right only child
                if(temp->value < temp->parentNode->value){
                        //Relink the tree
                        temp->parentNode->leftSubNode = temp->rightSubNode;
                }
                else{
                        //Relink the tree
                        temp->parentNode->rightSubNode = temp->rightSubNode;
                }
                temp->rightSubNode->parentNode = temp->parentNode;
                delete temp;
                temp = nullptr;
                //cout << x << " has been deleted\n";
                return;
        }

        //Case 3: Node has 2 children
        if(temp->leftSubNode != nullptr && temp->rightSubNode != nullptr){
                //Get the node to replace the deleted node's slot in the tree
                //to keep it linked together
                Node* replacementNode = new Node;
                replacementNode->value = FindMin(temp->rightSubNode)->value;
                replacementNode->parentNode = temp->parentNode;
                replacementNode->leftSubNode = temp->leftSubNode;
                replacementNode->rightSubNode = temp->rightSubNode;
                //Reset the parent node's child pointers
                if(x < temp->parentNode->value){
                        temp->parentNode->leftSubNode = replacementNode;
                }
                else{
                        temp->parentNode->rightSubNode = replacementNode;
                }
                //Readjust the subtree
                DeleteMin(temp->rightSubNode);

                delete temp;
                temp = nullptr;
                //cout << x << " has been deleted\n";
                return;
        }
        //cout << "ERROR: " << x << " could not be deleted.\n";
        return;
}

void BST::DeleteMin(Node* curNode){
        //If tree is empty or contains 1 element
        if(root == nullptr){
                //cout << "BST is empty.\n";
                return;
        }
        else if(root->leftSubNode == nullptr && root->rightSubNode == nullptr){
                //cout << root->value << " has been deleted\n";
                delete root;
                root = nullptr;
                return;
        }

        Node* temp = FindMin(curNode);
        //If the root of the tree is the min
        if(temp == root){
                //cout << temp->value << " has been deleted\n";
                temp = root->rightSubNode;
                root->rightSubNode->parentNode = nullptr;
                delete root;
                root = temp;
                //root = nullptr;
                return;
        }

        //If there are no children of the min
        if(temp->leftSubNode == nullptr && temp->rightSubNode == nullptr){
                //cout << temp->value << " has been deleted\n";
                temp->parentNode->leftSubNode = nullptr;
                delete temp;
                temp = nullptr;
                return;
        }

        //If there is a right child of min
        if(temp->rightSubNode != nullptr){
                //Relink the tree before deleting the min
                temp->parentNode->leftSubNode = temp->rightSubNode;
                temp->rightSubNode->parentNode = temp->parentNode;
                //Delete the min
                //cout << temp->value << " has been deleted\n";
                delete temp;
                temp = nullptr;
        }
        return;
}

void BST::DeleteMax(Node* curNode){
        //If tree is empty or contains 1 element
        if(root == nullptr){
                //cout << "BST is empty.\n";
                return;
        }
        else if(root->leftSubNode == nullptr && root->rightSubNode == nullptr){
                //cout << root->value << " has been deleted\n";
                delete root;
                root = nullptr;
                return;
        }

        Node* temp = FindMax(curNode);
        //If the root of the tree is the max
        if(temp == root){
                //cout << temp->value << " has been deleted\n";
                temp = root->leftSubNode;
                root->leftSubNode->parentNode = nullptr;
                delete root;
                root = temp;
                temp = nullptr;
                //root = nullptr;
                return;
        }

        //If there are no children of the max
        if(temp->leftSubNode == nullptr && temp->rightSubNode == nullptr){
                //cout << temp->value << " has been deleted\n";
                temp->parentNode->rightSubNode = nullptr;
                delete temp;
                temp = nullptr;
                return;
        }

        //If there is a left child of max
        if(temp->leftSubNode != nullptr && temp->rightSubNode == nullptr){
                //Relink the tree before deleting the max
                temp->parentNode->rightSubNode = temp->leftSubNode;
                temp->leftSubNode->parentNode = temp->parentNode;
                //Delete the max
                //cout << temp->value << " has been deleted\n";
                delete temp;
                temp = nullptr;
        }
        return;
}

Node* BST::FindMin(Node* curNode){
        if(root == nullptr){
                //cout << "The BST is empty.\n";
                return(nullptr);
        }
        Node* temp = curNode;//= root;
        //Traverse to the left most node
        while(temp->leftSubNode != nullptr){
                temp = temp->leftSubNode;
        }
        return(temp);
}

Node* BST::FindMax(Node* curNode){
        if(root == nullptr){
                //cout << "The BST is empty.\n";
                return(nullptr);
        }
        Node* temp = curNode;//= root;
        //Traverse to the right most node
        while(temp->rightSubNode != nullptr){
                temp = temp->rightSubNode;
        }
        return(temp);
}

void BST::Preorder(Node* curNode){
        if(root == nullptr){
                //cout << "The BST is empty.\n";
                return;
        }
        //Hit the end of a subtree
        if(curNode == nullptr){
                return;
        }
        //Print the value of the Node
        cout << curNode->value << " ";
        //Traverse left subtree
        Preorder(curNode->leftSubNode);
        //Traverse right subtree
        Preorder(curNode->rightSubNode);

        return;
}

void BST::Inorder(Node* curNode){
        if(root == nullptr){
                //cout << "The BST is empty.\n";
                return;
        }
        //Hit the end of a subtree
        if(curNode == nullptr){
                return;
        }
        //Traverse left subtree
        Inorder(curNode->leftSubNode);
        //Print the value of the Node
        cout << curNode->value << " ";
        //Traverse right subtree
        Inorder(curNode->rightSubNode);

        return;
}

void BST::Postorder(Node* curNode){
        if(root == nullptr){
                //cout << "The BST is empty.\n";
                return;
        }
        //Hit the end of a subtree
        if(curNode == nullptr){
                return;
        }
        //Traverse left subtree
        Postorder(curNode->leftSubNode);
        //Traverse right subtree
        Postorder(curNode->rightSubNode);
        //Print the value of the Node
        cout << curNode->value << " ";

        return;
}
