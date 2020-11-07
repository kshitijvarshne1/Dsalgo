/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 07-Nov-20
*   Time: 9:46 PM
*   File: PrintTopView.cpp
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

void printLeft(node *rootNode) {
    if (rootNode == NULL)
        return;
    printLeft(rootNode->left);
    cout << rootNode->data << " ";
}

void printright(node *rootNode) {
    if (rootNode == NULL)
        return;
    cout << rootNode->data << " ";
    printright(rootNode->right);
}

void printTopView(node *root) {
    node *rootNode = root;

    if (rootNode == NULL)
        return;
    printLeft(rootNode->left);
    cout << rootNode->data << " ";
    printright(rootNode->right);
}

int main() {
    node *root = levelOrderBuild();
    printTopView(root);
    return 0;
}
/* Input:-
 * 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
 *
 * output:-
 * 4 2 1 3
 * */


