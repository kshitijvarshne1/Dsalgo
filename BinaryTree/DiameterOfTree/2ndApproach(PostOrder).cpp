/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 04-Nov-20
*   Time: 6:27 PM
*   File: 2ndApproach.cpp
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

class Pair {
public:
    int height;
    int diameter;
};

Pair fastdiameter(node *root) {
    Pair p;
    if (root == NULL) {
        p.diameter = p.height = 0;
        return p;
    }

    Pair left = fastdiameter(root->left);
    Pair right = fastdiameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));

    return p;
}

int main() {
    node *root = buildTree();
    Pair p = fastdiameter(root);
    cout << "Height:- " << p.height << endl;
    cout << "Diameter:- " << p.diameter;
    return 0;
}

//
/* Input:-
 * 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
 * Output:-
 * Height:- 4
 * Diameter:- 6
 * */


