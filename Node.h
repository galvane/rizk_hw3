//
// Created by Evelyn on 6/27/2017.
//

#ifndef RIZK_HW3_NODE_H
#define RIZK_HW3_NODE_H

struct Node{
    int number;
    Node * left;
    Node * right;
    Node();
    Node(int);
    bool hasLeft();
    bool hasRight();
};

Node::Node(int data) {
    left = 0;
    right = 0;
    number = data;
}

bool Node::hasRight() {
    if(right == 0)
        return false;
    else
        return true;
}

bool Node::hasLeft() {
    if (left == 0)
        return false;
    else
        return true;
}

Node::Node() {
    number = 0;
    left = 0;
    right = 0;
}

#endif //RIZK_HW3_NODE_H
