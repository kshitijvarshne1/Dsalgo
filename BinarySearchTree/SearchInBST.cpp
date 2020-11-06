/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 06-Nov-20
*   Time: 2:51 PM
*   File: SearchInBST.cpp
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

//Accept the old root & data and returns the new root node
node *insertInBST(node *root, int data) {
    //Base Case
    if (root == NULL) {
        return new node(data);
    }
    //Recursive case-> Insert in Subtree
    if (data <= root->data) {
        root->left = insertInBST(root->left, data);
    } else {
        root->right = insertInBST(root->right, data);
    }
    return root;
}

node *build() {
    //Read a list of numbers till -1 and also these numbers will be inserted into BST
    int d;
    cin >> d;
    node *root = NULL;

    while (d != -1) {
        root = insertInBST(root, d);
        cin >> d;
    }
    return root;
}

bool searchInBST(node *root, int data) {
    if (root == NULL) {
        return false;
    }
    if (root->data == data) {
        return true;
    }
    //Recursively search in left and right subtree
    if (data <= root->data) {
        return searchInBST(root->left, data);
    } else {
        return searchInBST(root->right, data);
    }
}

int main() {
    node *root = build();
    int data;
    cin >> data;
    if (searchInBST(root, data)) {
        cout << "Present";
    } else {
        cout << "Not Present";
    }
    return 0;
}
/*Input:-
5 3 7 1 6 8 -1
7
Output:-
Present
*/



