/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 30-Oct-20
*   Time: 5:20 PM
*   File: RecusivelyReverseALinkedList.cpp
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

node *recursivelyReverse(node *head) {
    //smallest linked list
    if (head->next == NULL or head == NULL) {
        return head;
    }
    //Recursive case
    node *shead = recursivelyReverse(head->next);

    node *temp = head->next;
    temp->next = head;
    head->next = NULL;
    return shead;

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
    head = recursivelyReverse(head);
    print(head);

    return 0;
}


