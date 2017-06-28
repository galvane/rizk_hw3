#include "ArgumentManager.h"
#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "Node.h"

int *make_array(string basic_string, int &size);

void print(int * arr, int size);

using namespace std;


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: heap preorder=<filename> inorder=<filename>\n";
    }
    ArgumentManager am(argc, argv);

    string filename_inorder = "in4.txt";
    string filename_preorder = "pre4.txt";

    int size = 0;
    int* inorder = make_array(filename_inorder,size);
    int test_size = size;
    int* preorder = make_array(filename_preorder,size);
    if (size != test_size) cout << "UNEQUAL SIZES";

    print(inorder,size);
    cout << "now.. \n";
    print(preorder,size);





    cout << "\nThis is the linked tree: " << endl;
    BinaryTree t;
    Node * root = (t.buildTree(inorder,preorder,0,size-1));
    t.print(root);
    cout << '\n';
    cout << "Height of tree is: " << t.height(root);
    cout <<"\nPrinted level order: ";t.printLevelOrder(root);













    return 0;
}

void print(int * arr, int size){
    for (int i = 0; i < size ; ++i) {
        cout << *(arr+i) << " ";
    }
}
int *make_array(string filename, int &size) {
    ifstream ifs(filename);

    string file = "";
    string temp = "";
    if (ifs.is_open()) {
        while (ifs.good()) {
            getline(ifs,temp);
            file.append(" "+temp+" ");
        }
    }

    bool isnum = false;
    int start = 0;
    char c;
    size = 0;
    for (int i = 0; i < strlen(file.c_str()); ++i) { // find size first
        c = file.at(i);
        if ((c >= '0' && c <= '9') || c == '-') {
            if ( isnum == false ) {
                start = i;
            }
            isnum = true;
        }
        else {
            if ( isnum == true ) {
                size++;
            }
            isnum = false;
        }
    }
    // make array second
    int* out = new int[size];
    int i_out = 0;

    for (int i = 0; i < strlen(file.c_str()); ++i) {
        c = file.at(i);
        if ((c >= '0' && c <= '9') || c == '-') {
            if ( isnum == false ) {
                start = i;
            }
            isnum = true;
        }
        else {
            if ( isnum == true ) {
                temp = file.substr(start,i-start);
                *(out+i_out) = atoi(temp.c_str());
                i_out++;
            }
            isnum = false;
        }
    }


    return out;
}


//    Node *node = new Node();
//    BinaryTree t(node);
//    node->number = *input;
//    node->left = new Node(*(input+1));
//    node->left->left = new Node(*(input+2));
//    node->left->right = new Node(*(input+3));
//    node->right = new Node(*(input+4));
//    node->right->left = new Node(*(input+5));
//    t.print(node);



//    Node* t;
//    t = (Node *) input;
//    BinaryTree tree(t);
//    Node * treePtr = tree.buildTree(input, input2,0,length);
//    tree.print(treePtr);
