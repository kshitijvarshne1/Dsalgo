/*
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 31-Oct-20
*   Time: 8:34 PM
*   File: K_append.cpp
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

void insertAtTail(node *&head, int data) {
    if (head == NULL) {
        head = new node(data);
        return;
    }
    node *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;

    }
    tail->next = new node(data);
    return;
}

node *K_append(node *head, int k) {
    node *fast = head;
    node *slow = head;
    int c = 1;
    while (c < k) {
        fast = fast->next;
        c++;
    }
    node *prev;
    while (fast->next != NULL) {
        prev = slow;
        fast = fast->next;
        slow = slow->next;
        //prev=prev->next;
    }
    fast->next = head;
    head = slow;
    prev->next = NULL;

    return head;
}

void print(node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {

    int n1;
    node *head = NULL;
    int i, x, k;
    cin >> n1;
    for (i = 0; i < n1; i++) {
        cin >> x;
        insertAtTail(head, x);
    }
    cin >> k;
    k = k % n1;
    if (k == 0) {
        print(head);
    } else {
        node *final = K_append(head, k);

        print(final);
    }
    return 0;
}

