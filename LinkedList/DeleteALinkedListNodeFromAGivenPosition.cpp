/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 31-Oct-20
*   Time: 2:18 PM
*   File: DeleteALinkedListNodeFromAGivenPosition.cpp
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

void delete1(node *&head, int position) {

    if (head == NULL)
        return;

    node *temp = head;

    if (position == 0) {
        head = temp->next;
        delete (temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        return;
    }

    node *next = temp->next->next;

    delete (temp->next);

    temp->next = next;
}

void print(node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


int main() {

    int a, b;
    cin >> a;
    cin >> b;
    node *head = NULL;
    while (a--) {
        int k;
        cin >> k;
        insertAtHead(head, k);
    }
    reverseLinkedList(head);
    while (b--) {
        int x;
        cin >> x;
        delete1(head, x);
        print(head);
        cout << endl;

    }


    return 0;
}


