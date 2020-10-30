/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 30-Oct-20
*   Time: 6:20 PM
*   File: kthNodeFromTheEndOfLinkedList.cpp
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

node *take_input() {
    int d;
    cin >> d;
    node *head = NULL;
    while (d != -1) {
        insertAtHead(head, d);
        cin >> d;
    }
    return head;
}

node *kthNodeFromTheEnd(node *head, int k) {
    if (head == NULL or head->next == NULL) {
        return head;
    }
    node *slow = head;
    node *fast = head;
    for (int i = 0; i < k; i++) {
        fast = fast->next;
    }


    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
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
    node *head = take_input();
    int k;
    cin >> k;
    reverseLinkedList(head);
    node *kth = kthNodeFromTheEnd(head, k);
    cout << kth->data;

    return 0;
}

