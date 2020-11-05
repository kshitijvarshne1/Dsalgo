/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 05-Nov-20
*   Time: 11:42 AM
*   File: CreateTreeFromInorderAndPreorder.cpp
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

node *createTreeFromTraversal(int *in, int *pre, int s, int e) {
    static int i = 0;
    //Base Case
    if (s > e) {
        return NULL;
    }
    //Recursive Case
    node *root = new node(pre[i]);
    int index = -1;
    for (int j = s; j <= e; j++) {
        if (in[j] == pre[i]) {
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTraversal(in, pre, s, index - 1);
    root->right = createTreeFromTraversal(in, pre, index + 1, e);
    return root;
}

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
    return;
}


int main() {
    int n;
    cin >> n;
    int in[1000];
    int pre[1000];
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    node *root = createTreeFromTraversal(in, pre, 0, n - 1);
    bfs(root);
    return 0;
}


/*Input:
    8
    3 2 8 4 1 6 7 5
    1 2 3 4 8 5 6 7
Output:-
   1
   2 5
   3 4 6
   8 7
*/



