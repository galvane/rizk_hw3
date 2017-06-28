#include <iostream>
#include <cmath>
#include "Node.h"

#ifndef RIZK_HW3_BINARYTREE_H
#define RIZK_HW3_BINARYTREE_H
using namespace std;

class BinaryTree{
    Node* root = 0;
    int numNodes = 0;
    int levels = 0;
public:
    BinaryTree();
    BinaryTree(Node*);
    int height(Node*);
    Node *buildTree(int * ,int*, int, int);
    int iParent(int);
    int iLeftChild(int);
    int iRightChild(int);
    int iLeftSibling(int);
    int iRightSibling(int);
    void totalNodes(int);
    void arrangePreOrder(int * input);
    int numLevels();
    void print(Node*);
    int search(int * arr, int beg, int end, int value);
    ~BinaryTree();

    void printGivenLevel(Node *root, int level);

    void printLevelOrder(Node *root);
};
BinaryTree::BinaryTree() {}

BinaryTree::BinaryTree(Node * r) { root = r;}

int BinaryTree::height(Node* node) {
    if (node==NULL)
        return 0;
    else{
        int lheight = height(node->left);
        int rheight = height(node->right);

    if (lheight > rheight)
        return(lheight+1);
    else
        return(rheight+1);
    }
}
void BinaryTree::printLevelOrder(Node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++) {
        printGivenLevel(root, i);
        cout << endl;
    }

}

void BinaryTree::printGivenLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->number;
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

Node* BinaryTree::buildTree(int *inOrder,int *preOrder, int beg, int end) {
    static int preorder_index = 0;
    if(beg > end)
        return NULL;

    Node * current = new Node(*(preOrder+preorder_index++));

    //if there is no children
    if(beg == end)
        return current;

    int inorder_index = search(inOrder, beg, end, current->number);

    //left and right subtrees
    current->left = buildTree(inOrder, preOrder, beg, inorder_index-1);
    current->right = buildTree(inOrder, preOrder, inorder_index+1, end);

    return current;
}



BinaryTree::~BinaryTree() {}

int BinaryTree::iParent(int iNumber) {
    if (iNumber != 0)
        return (iNumber-1)/2;
    else
        return -1;
}

int BinaryTree::iLeftChild(int iNumber) {
    int iLeftChild = 2*iNumber+1;
    if(iLeftChild <= numNodes)
        return iLeftChild;
    else
        return -1;
}

int BinaryTree::iRightChild(int iNumber) {
    int iRightChild = 2*iNumber+2;
    if(iRightChild <=numNodes)
        return iRightChild;
    else
        return -1;
}

int BinaryTree::iLeftSibling(int iNumber) {
    int iLeftSibling = iNumber-1;
    if(iLeftSibling%2 == 0)
        return iLeftSibling;
    else
        return -1;
}

int BinaryTree::iRightSibling(int iNumber) {
    int iRightSibling = iNumber+1;
    if((iRightSibling%2 != 0) && (iRightSibling <= numNodes))
        return iRightSibling;
    else
        return -1;
}

void BinaryTree::totalNodes(int lengthofArray){ numNodes = lengthofArray; }

void BinaryTree::arrangePreOrder(int *input) {

}

int BinaryTree::numLevels() {
    return ceil(log2(numNodes+1));
}

void BinaryTree::print(Node * node) {
    if(node == 0)
        return;


    print(node->left);
    cout << node->number << " ";
    print (node->right);

}

int BinaryTree::search(int *arr, int beg, int end, int value) {
    for (int i = beg; i <= end; ++i) {
        if((*(arr+i)) == value)
            return i;
    }
}


#endif //RIZK_HW3_BINARYTREE_H






//int rec() {
//    if (is_left) {
//        int a1 = rec(left);
//        if (is_right) int a2 = rec(right);
//    }
//}