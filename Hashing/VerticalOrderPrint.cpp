/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 11-Nov-20
*   Time: 7:43 PM
*   File: VerticalOrderPrint.cpp
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

void verticalOrderPrint(node *root, int d, map<int, vector<int>> &m) {
    //base case
    if (root == NULL) {
        return;
    }
    //otherwise
    m[d].push_back(root->data);
    verticalOrderPrint(root->left, d - 1, m);
    verticalOrderPrint(root->right, d + 1, m);
    return;
}

int main() {
    int n;
    cin >> n;
    node *root = levelOrderBuild();
    map<int, vector<int>> m;
    int d = 0;
    verticalOrderPrint(root, d, m);

    for (auto p: m) {
        for (auto x : p.second) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
/*Input:-
in this input fist integer 4 denoting no of levels
4 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
Output:-
4
2
1 5 6
3 8
7
9*/
