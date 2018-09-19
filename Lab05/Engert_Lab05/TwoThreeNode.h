/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 05
*
* Two-Three Trees with level order print:
*       Building a 2-3 tree from an input data file, the tree contains
*       multiple min/max functions and a level order print of the contents
*******************************************************************************/
#ifndef TWOTHREENODE_H
#define TWOTHREENODE_H

class TwoThreeNode{
        public:
                TwoThreeNode();

                //Pass in a bool defining the node's isInterior value
                void setIsInterior(bool x);
                //Pass in an int defining the node's value
                void setValue(int val);
                //Pass in an int defining the node's minSecond value
                void setMinSecond(int val);
                //Pass in an int defining the node's minThird value
                void setMinThird(int val);
                //Pass in a TwoThreeNode pointer defining the node's parent
                void setParent(TwoThreeNode* parent);
                //Pass in a TwoThreeNode pointer defining the node's first child
                void setFirstChild(TwoThreeNode* child);
                //Pass in a TwoThreeNode pointer defining the node's second child
                void setSecondChild(TwoThreeNode* child);
                //Pass in a TwoThreeNode pointer defining the node's third child
                void setThirdChild(TwoThreeNode* child);
                //Sets the node's child pointers to nullptr
                void adoption();

                //Returns a bool representing the node's isInterior value
                bool getIsInterior();
                //Returns an int representing the node's value
                int getValue();
                //Returns an int representing the node's minSecond value
                int getMinSecond();
                //Returns an int representing the node's minThird value
                int getMinThird();
                //Returns a TwoThreeNode pointer to the Node's parent
                TwoThreeNode* getParent();
                //Returns a TwoThreeNode pointer to the Node's first child
                TwoThreeNode* getFirstChild();
                //Returns a TwoThreeNode pointer to the Node's second child
                TwoThreeNode* getSecondChild();
                //Returns a TwoThreeNode pointer to the Node's third child
                TwoThreeNode* getThirdChild();


        private:
                bool isInterior;
                int value;
                int minSecond;
                int minThird;
                TwoThreeNode* parentNode;
                TwoThreeNode* firstChild;
                TwoThreeNode* secondChild;
                TwoThreeNode* thirdChild;

};
#endif
