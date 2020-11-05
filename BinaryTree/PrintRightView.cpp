/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 05-Nov-20
*   Time: 1:42 PM
*   File: PrintRightView.cpp
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

void printRightView(node *root, int level, int &maxlevel) {
    if (root == NULL) {
        return;
    }
    if (maxlevel < level) {
        //have discovered a new level
        cout << root->data << " ";
        maxlevel = level;
    }
    //right
    printRightView(root->right, level + 1, maxlevel);
    // left
    printRightView(root->left, level + 1, maxlevel);
}

int main() {
    node *root = buildTree();
    int maxlevel = -1;
    printRightView(root, 0, maxlevel);
    return 0;
}
/* Input:-
 * 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
 *
 * output:-
 * 8 3 14 13
 * */

