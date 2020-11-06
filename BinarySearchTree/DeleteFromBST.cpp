/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 06-Nov-20
*   Time: 5:57 PM
*   File: DeleteFromBST.cpp
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

//Accepts the old root node & data and returns the new root node
node *insertInBST(node *root, int data) {
    //Base Case
    if (root == NULL) {
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
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

node *deleteInBST(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        root->left = deleteInBST(root->left, data);
        return root;
    } else if (data == root->data) {
        //found the node to delete 3 case
        //node with a children->leaf case
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        //2.case only 1 chile
        if (root->left != NULL && root->right == NULL) {
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->right != NULL && root->left == NULL) {
            node *temp = root->right;
            delete root;
            return temp;
        }
        //3.case 2 children
        node *replace = root->right;
        //find the inorder successor from the right subtree
        while (replace->left != NULL) {
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteInBST(root->right, replace->data);
        return root;
    } else {
        root->right = deleteInBST(root->right, data);
        return root;
    }
}


//Print the BST Level By Level
void bfs(node *root) {
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
            cout << f->data << ",";
            q.pop();

            if (f->left) {
                q.push(f->left);
            }
            if (f->right) {
                q.push(f->right);
            }
        }
    }
    return;
}

//Inorder Print
void inorder(node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << ",";
    inorder(root->right);
}

int main() {
    node *root = build();
    int k;
    cin >> k;
    root = deleteInBST(root, k);
    cout << "inorder print" << endl;
    inorder(root);
    cout << endl << "bfs print" << endl;
    bfs(root);

    return 0;
}
/*
5 3 7 1 6 8 -1
3
inorder print
1,5,6,7,8,
bfs print
5,
1,7,
6,8,
 */

