/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 04-Feb-21
*   Time: 12:42 AM
*   File: BasicOfLinkedList.cpp
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
# define cin ios_base::sync_with_stdio(false);cin.tie(NULL); cin
using namespace std;

class node {
public:
    int data;
    node *next;

    //Constructor
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
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void print(node *head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
}

void printRecursive(node *head) {
    if (head == NULL) {
        return;
    }
    cout << head->data << "-> ";
    print(head->next);

}

int length(node *head) {
    int c = 0;
    while (head != NULL) {
        c += 1;
        head = head->next;
    }
    return c;
}

void insertAtMiddle(node *&head, int d) {
    int middle = length(head) / 2;
    if (head == NULL or middle == 0) {
        insertAtHead(head, d);
        return;
    }
    // take middle-1 jumps
    int jumps = 1;
    node *temp = head;
    while (jumps <= middle - 1) {
        temp = temp->next;
        jumps += 1;
    }
    //create a new node
    node *n = new node(d);
    n->next = temp->next;
    temp->next = n;
    return;
}

void insertAtTail(node *&head, int d) {
    if (head == NULL) {
        head = new node(d);
        return;
    }
    node *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
}

void deleteHead(node *&head) {
    if (head == NULL) {
        return;
    }
    node *temp = head->next;
    // temp is local variable (static variable) , after execution of this function it will destroy automatically
    delete head;
    head = temp;
}

bool searchNode(node *head, int element) {
    while (head != NULL) {
        if (element == head->data) {
            return true;
        }
        head = head->next;
    }
    return false;
}

// recursively searching
bool recursivelySearchNode(node *head, int element) {
    if (head == NULL) {
        return false;
    }
    if (head->data == element) {
        return true;
    }
    recursivelySearchNode(head->next, element);
}

int main() {
    node *head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    printRecursive(head);
    insertAtMiddle(head, 55);
    cout << endl;
    print(head);
    cout << endl;
    insertAtTail(head, 1111);
    print(head);
    cout << endl;
    deleteHead(head);
    print(head);
    cout << endl << searchNode(head, 5) << endl;
    print(head);
    cout << endl << searchNode(head, 55) << endl;
    return 0;
}