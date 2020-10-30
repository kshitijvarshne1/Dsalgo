/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 30-Oct-20
*   Time: 5:44 PM
*   File: MidPointOfALinkedList.cpp
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

//Runner technique
// slow horse and fast horse
node *midpoint(node *head) {
    if (head == NULL or head->next == NULL) {
        return head;
    }
    node *slow = head;
    node *fast = head;
    /*
     * for odd we get n/2
     * for even we get n/2
     * if we want same for odd but for even we want (n/2)+1
     * then do one thing in line no 47 is that
     *  node *fast = head->next;
     *
     * */

    while (fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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
    node *mid = midpoint(head);
    cout << mid->data;

    return 0;
}

