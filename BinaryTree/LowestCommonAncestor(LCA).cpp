/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 06-Nov-20
*   Time: 12:08 AM
*   File: LowestCommonAncestor.cpp
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

//assumption both a and b are present in the terr and all keys are unique
node *lca(node *root, int a, int b) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == a or root->data == b) {
        return root;
    }
    //Search in left and right subtree
    node *leftans = lca(root->left, a, b);
    node *rightans = lca(root->right, a, b);
    if (leftans != NULL and rightans != NULL) {
        return root;
    }
    if (leftans != NULL) {
        return leftans;
    }
    return rightans;
}

int main() {
    node *root = levelOrderBuild();
    int a, b;
    cin >> a >> b;
    node *ans = lca(root, a, b);
    cout << ans->data;
    return 0;
}
/* Input:-
 * 1 2 3 4 5 -1 -1 6 7 8 9 -1 -1 10 11 -1 -1 -1 -1 -1 -1 -1 -1
 * 4
 * 11
 * output:-
 * 4
 * */



