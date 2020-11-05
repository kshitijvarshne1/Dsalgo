/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 05-Nov-20
*   Time: 5:42 PM
*   File: LevelOrderBuild.cpp
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
    node *root = levelOrderBuild();
    bfs(root);

    return 0;
}
/* Input:-
 * 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
 *
 * output:-
 * 1
 * 2 3
 * 4 5 6
 * */


