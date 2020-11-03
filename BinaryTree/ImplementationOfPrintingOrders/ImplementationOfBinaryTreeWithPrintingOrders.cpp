/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 03-Nov-20
*   Time: 9:18 PM
*   File: ImplementationOfBinaryTreeWithPrintingOrders.cpp
*/
# include<iostream>
# include<climits>
# include<cmath>
# include<algorithm>
# include<bits/stdc++.h>
# include<cstring>
# include<iomanip>
# include<vector>
# include<stack>
# include<queue>

using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }

};

node *buildTree() {
    int d;
    cin >> d;

    if (d == -1) {
        return NULL;
    }
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printPreOrder(node *root) {
    if (root == NULL) {
        return;
    }
    //otherwise print root first followed by subtree(children)
    //root left right
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(node *root) {
    if (root == NULL) {
        return;
    }
    //otherwise left root right
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void printPostOrder(node *root) {
    if (root == NULL) {
        return;
    }
    //otherwise left right root
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int main() {
    node *root = buildTree();
    printPreOrder(root);
    cout << endl;
    printInOrder(root);
    cout << endl;
    printPostOrder(root);
    return 0;
}

//
/* Input:-
 * 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
 * output:-
 *
 *  Pre order  8 10 1 6 9 7 3 14 13
 *  In order   1 10 9 6 7 8 3 13 14
 *  Post Order 1 9 7 6 10 13 14 3 8
 * */
