/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 06-Nov-20
*   Time: 2:37 PM
*   File: BuildBST.cpp
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

void printInOrder(node *root) {
    if (root == NULL) {
        return;
    }
    //otherwise left root right
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

node *bfs(node *root) {
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node *f = q.front();
        if (f == NULL) {
            cout << endl;
            q.pop();
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << f->data << " ";
            q.pop();

            if (f->left) {
                q.push(f->left);
            }
            if (f->right) {
                q.push(f->right);
            }
        }
    }
    return root;
}


int main() {
    node *root = build();
    cout << "Inorder Printing:- " << endl;
    printInOrder(root);
    cout << endl;
    cout << "Level Order Printing:-" << endl;
    bfs(root);
    return 0;
}
/*Input:-
5 3 7 1 6 8 -1
Output:-
Inorder Printing:-
1 3 5 6 7 8
Level Order Printing:-
5
3 7
1 6 8*/



