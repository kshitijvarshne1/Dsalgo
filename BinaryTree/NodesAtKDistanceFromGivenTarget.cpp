/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 05-Nov-20
*   Time: 11:22 PM
*   File: NodesAtKDistanceFromGivenTarget.cpp
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

void printKLevel(node *root, int k) {
    if (root == NULL) {
        return;
    }
    if (k == 0) {
        cout << root->data << " ";
        return;
    }
    printKLevel(root->left, k - 1);
    printKLevel(root->right, k - 1);
    return;
}

int printAtDistanceK(node *root, node *target, int k) {
    //base case
    if (root == NULL) {
        return -1;
    }
    //reach the target the node
    if (root == target) {
        printKLevel(target, k);
        return 0;
    }
    //next step->ancestor
    int DL = printAtDistanceK(root->left, target, k);
    if (DL != -1) {
        //Again there are two cases
        //1->print ancestor itself OR
        //You need go to the right ancestor
        if (DL + 1 == k) {
            cout << root->data << " ";
        } else {
            printKLevel(root->right, k - 2 - DL);
        }
        return 1 + DL;
    }
    int DR = printAtDistanceK(root->right, target, k);
    if (DR != -1) {
        if (DR + 1 == k) {
            cout << root->data << " ";
        } else {
            printKLevel(root->left, k - 2 - DR);
        }
        return 1 + DR;
    }
    //Node was not present in left and right of given tree
    return -1;
}

int main() {
    node *root = levelOrderBuild();
    node *target = root->left->left;
    int k;
    cin >> k;
    printAtDistanceK(root, target, k);

    return 0;
}
/* Input:-
 * //level Order Input
 * 1 2 3 4 5 -1 -1 6 7 8 9 -1 -1 10 11 -1 -1 -1 -1 -1 -1 -1 -1
 *
 * output:-
 * 8 9 3
 *
 * */


