/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 04-Nov-20
*   Time: 1:58 PM
*   File: CountAndSumOfNodes.cpp
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


int count(node *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

int sum(node *root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + sum(root->left) + sum(root->right);
}

int main() {
    node *root = buildTree();
    cout << count(root) << endl;;
    cout << sum(root);

    return 0;
}


/* Input:-
 * 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
 * output:-
 *  9
 *  71
 * */
