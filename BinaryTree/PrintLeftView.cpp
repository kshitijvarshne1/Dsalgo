/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 05-Nov-20
*   Time: 6:11 PM
*   File: PrintLeftView.cpp
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

node *levelOrderBuild() {
    int d;
    cin >> d;
    node *root = new node(d);
    queue<node *> q;
    q.push(root);

    while (!q.empty()) {
        node *n = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 != -1) {
            n->left = new node(c1);
            q.push(n->left);
        }
        if (c2 != -1) {
            n->right = new node(c2);
            q.push(n->right);
        }
    }
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
    // left
    printRightView(root->left, level + 1, maxlevel);
    //right
    printRightView(root->right, level + 1, maxlevel);

}

int main() {
    node *root = levelOrderBuild();
    int maxlevel = -1;
    printRightView(root, 0, maxlevel);
    return 0;
}
/* Input:-
 * 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
 *
 * output:-
 * 1 2 4
 * */


