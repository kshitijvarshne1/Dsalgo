/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 30-Oct-20
*   Time: 9:01 PM
*   File: MergeSort.cpp
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

node *midpoint(node *head) {
    if (head == NULL or head->next == NULL) {
        return head;
    }
    node *slow = head;
    node *fast = head->next;
    /*
     * for odd we get n/2
     * for even we get (n/2)+1
     * if we want same for odd but for even we want (n/2)
     * then do one thing in line no 47 is that
     *  node *fast = head;
     *
     * */
    while (fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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

node *mergeSort(node *head) {
    //base case
    if (head == NULL or head->next == NULL) {
        return head;
    }
    // Recursive Case
    //1.Break
    node *mid = midpoint(head);
    node *a = head;
    node *b = mid->next;

    mid->next = NULL;
    //2.Recursive sort the two parts
    a = mergeSort(a);
    b = mergeSort(b);

    //3. merge them
    node *c = mergeSortedTwoLinkedList(a, b);
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

    int a, b;
    cin >> a;
    node *head = NULL;
    while (a--) {
        int k;
        cin >> k;
        insertAtHead(head, k);
    }
    reverseLinkedList(head);
    head = mergeSort(head);
    print(head);

    return 0;
}


