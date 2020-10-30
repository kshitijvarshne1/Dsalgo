/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 30-Oct-20
*   Time: 7:44 PM
*   File: MergeTwoSortedLinkedList.cpp
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


node *mergeSortedTwoLinkedList(node *a, node *b) {
    //base case
    if (a == NULL) {
        return b;
    }
    if (b == NULL) {
        return a;
    }
    //take a head pointer
    node *c;
    if (a->data < b->data) {
        c = a;
        c->next = mergeSortedTwoLinkedList(a->next, b);
    } else {
        c = b;
        c->next = mergeSortedTwoLinkedList(a, b->next);
    }
    return c;


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
        cout << head->data << " ";
        head = head->next;
    }
}


int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a;
        node *head1 = NULL;
        node *head2 = NULL;
        while (a--) {
            int k;
            cin >> k;
            insertAtHead(head1, k);
        }
        cin >> b;
        while (b--) {
            int k;
            cin >> k;
            insertAtHead(head2, k);

        }
        reverseLinkedList(head1);
        reverseLinkedList(head2);
        node *newHead = mergeSortedTwoLinkedList(head1, head2);
        print(newHead);
        cout << endl;

    }
    return 0;
}
