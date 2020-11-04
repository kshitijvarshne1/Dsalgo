/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 04-Nov-20
*   Time: 5:04 PM
*   File: 1stApproach.cpp
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

int height(node *root) {

    if (root == NULL) {
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);

    return max(ls, rs) + 1;
}

int diameter(node *root) {
    if (root == NULL) {
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1 + h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1, max(op2, op3));
}


int main() {
    node *root = buildTree();
    cout << diameter(root);
    return 0;
}

//
/* Input:-
 * 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
 * output:-
 *  6
 *
 * */
