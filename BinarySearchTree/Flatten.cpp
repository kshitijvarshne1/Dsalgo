/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 06-Nov-20
*   Time: 8:01 PM
*   File: Flatten.cpp
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

//Accepts the old root node & data and returns the new root node
node *insertInBST(node *root, int data) {
    //Base Case
    if (root == NULL) {
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if (data <= root->data) {
        root->left = insertInBST(root->left, data);
    } else {
        root->right = insertInBST(root->right, data);
    }
    return root;
}


node *build() {
    //Read a list of numbers till -1 and also these numbers will be inserted into BST
    int d;
    cin >> d;

    node *root = NULL;

    while (d != -1) {
        root = insertInBST(root, d);
        cin >> d;
    }
    return root;
}

class LinkedList {
public:
    node *head;
    node *tail;
};

LinkedList flatten(node *root) {
    LinkedList l;
    if (root == NULL) {
        l.head = l.tail = NULL;
        return l;
    }
    //leaf node
    if (root->left == NULL && root->right == NULL) {
        l.head = l.tail = root;
        return l;
    }
    //left id not null
    if (root->left != NULL && root->right == NULL) {
        LinkedList leftll = flatten(root->left);
        leftll.tail->right = root;
        l.head = leftll.head;
        l.tail = root;
        return l;
    }
    //Right is not null
    if (root->left == NULL && root->right != NULL) {
        LinkedList rightll = flatten(root->right);
        root->right = rightll.head;
        l.head = root;
        l.tail = rightll.tail;
        return l;
    }
    //Both side are not null
    LinkedList leftll = flatten(root->left);
    LinkedList rightll = flatten(root->right);

    leftll.tail->right = root;
    root->right = rightll.head;
    l.head = leftll.head;
    l.tail = rightll.tail;
    return l;
}


int main() {
    node *root = build();
    // bfs(root);
    // cout<<endl;
    LinkedList final = flatten(root);
    node *temp = final.head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    return 0;
}
/*
 Input:-
 5 3 7 1 6 8 -1
 Output:-
 1 3 5 6 7 8
 */


