/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 01-Nov-20
*   Time: 12:17 PM
*   File: IsPallindromicLinkedList.cpp
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

    //Constructor
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
}

void take_input(node *&head) {
    int n;
    cin >> n;
    while (n--) {
        int data;
        cin >> data;
        insertAtTail(head, data);
    }
    return;
}

void print(node *head) {
    if (head == NULL) {
        return;
    }
    cout << head->data << " ";
    print(head->next);
}

bool pallindromeCheck(node *head) {
    node *slow = head;
    node *fast = head;
    node *mid = NULL;
    while (fast != NULL and fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    //odd->fast is not null
    if (fast != NULL) {
        mid = slow->next;
    } else {
        mid = slow;
    }
    node *previous = NULL;
    node *next = NULL;

    while (mid != NULL) {
        next = mid->next;
        mid->next = previous;
        previous = mid;
        mid = next;
    }
    while (previous != NULL) {
        if (previous->data != head->data) {
            return false;
        }
        previous = previous->next;
        head = head->next;
    }
    return true;
}

int main() {
    int k;
    node *head = NULL;
    take_input(head);
    if (pallindromeCheck(head)) {
        cout << "true";
    } else {
        cout << "false";
    }
}
