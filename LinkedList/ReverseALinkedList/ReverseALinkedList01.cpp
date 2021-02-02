/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 30-Oct-20
*   Time: 5:04 PM
*   File: ReverseALinkedList01.cpp
*/
# include<iostream>
# include<climits>
# include<cmath>
# include<algorithm>
# include<bits/stdc++.h>
# include<cstring>
# include<iomanip>
# include<vector>

using namespace std;

class node {
public:
    int data;
    node *next;

    node(int d) {
        data = d;
        next = NULL;
    }
};

void insertAtHead(node *&head, int d) {
    if (head == NULL) {
        head = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = head;
    head = n;
}

void reverseLinkedList(node *&head) {
    node *c = head;
    node *p = NULL;
    node *n;
    while (c != NULL) {
        //save the next node
        n = c->next;
        c->next = p;
        //update p and c take them 1 step forward
        p = c;
        c = n;
    }
    head = p;
}

void print(node *head) {
    while (head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
}

int main() {
    node *head = NULL;
    int n;
    cin >> n;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        insertAtHead(head, a);
    }
    reverseLinkedList(head);

    print(head);

    return 0;
}

