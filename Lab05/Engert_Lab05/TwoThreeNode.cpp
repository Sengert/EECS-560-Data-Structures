/*******************************************************************************
* Author: Samuel Engert
* Course: EECS 560
* Lab 05
*
* Two-Three Trees with level order print:
*       Building a 2-3 tree from an input data file, the tree contains
*       multiple min/max functions and a level order print of the contents
*******************************************************************************/
#include "TwoThreeNode.h"
#include <iostream>

using namespace std;


TwoThreeNode::TwoThreeNode(){
        isInterior = false;
        value = -1;
        minSecond = -1;
        minThird = -1;
        parentNode = nullptr;
        firstChild = nullptr;
        secondChild = nullptr;
        thirdChild = nullptr;

        return;
}

void TwoThreeNode::setIsInterior(bool x){
        isInterior = x;
        return;
}

void TwoThreeNode::setValue(int val){
        value = val;
        return;
}

void TwoThreeNode::setMinSecond(int val){
        minSecond = val;
        return;
}

void TwoThreeNode::setMinThird(int val){
        minThird = val;
        return;
}

void TwoThreeNode::setParent(TwoThreeNode* parent){
        parentNode = parent;
        return;
}

void TwoThreeNode::setFirstChild(TwoThreeNode* child){
        firstChild = child;
        return;
}

void TwoThreeNode::setSecondChild(TwoThreeNode* child){
        secondChild = child;
        return;
}

void TwoThreeNode::setThirdChild(TwoThreeNode* child){
        thirdChild = child;
        return;
}

void TwoThreeNode::adoption(){
        firstChild = nullptr;
        secondChild = nullptr;
        thirdChild = nullptr;
}

bool TwoThreeNode::getIsInterior(){
        return(isInterior);
}

int TwoThreeNode::getValue(){
        return(value);
}

int TwoThreeNode::getMinSecond(){
        return(minSecond);
}

int TwoThreeNode::getMinThird(){
        return(minThird);
}

TwoThreeNode* TwoThreeNode::getParent(){
        return(parentNode);
}

TwoThreeNode* TwoThreeNode::getFirstChild(){
        return(firstChild);
}

TwoThreeNode* TwoThreeNode::getSecondChild(){
        return(secondChild);
}

TwoThreeNode* TwoThreeNode::getThirdChild(){
        return(thirdChild);
}
