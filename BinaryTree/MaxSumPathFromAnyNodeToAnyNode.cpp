/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 05-Dec-20
*   Time: 10:19 PM
*   File: MaxSumPathFromAnyNodeToAnyNode.cpp
*/
# include<iostream>
# include<bits/stdc++.h>
# include<climits>
# include<cmath>
# include<algorithm>
# include<cstring>
# include<iomanip>
# include<vector>
# include<stack>
# include<queue>
# include<map>
# include<unordered_map>
# include<unordered_set>

# define modValue 1e9 + 7
# define ll long long int
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

class Pair {
public:
    int branchSum;
    int maxSum;

    Pair() {
        branchSum = 0;
        maxSum = 0;
    }
};

Pair maxSumPath(node *root) {
    Pair p;
    if (root == NULL) {
        return p;
    }
    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    int op1 = root->data;
    int op2 = left.branchSum + root->data;
    int op3 = right.branchSum + root->data;
    int op4 = left.branchSum + right.branchSum + root->data;

    int current_ans_through_root = max(op1, max(op2, max(op3, op4)));

    p.branchSum = max(left.branchSum, max(right.branchSum, 0)) + root->data;
    p.maxSum = max(left.maxSum, max(right.maxSum, current_ans_through_root));

    return p;
}


int main() {
    node *root = levelOrderBuild();
    cout << maxSumPath(root).maxSum;
    return 0;
}



