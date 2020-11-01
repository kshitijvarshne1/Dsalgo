/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 01-Nov-20
*   Time: 5:46 PM
*   File: ReverseAStackUsingRecursion.cpp
*/
# include<iostream>
# include<climits>
# include<cmath>
# include<algorithm>
# include<bits/stdc++.h>
# include<cstring>
# include<iomanip>
# include<vector>
# include<stack>

using namespace std;

void insertAtBottom(stack<int> &s, int x) {
    //base case
    if (s.empty()) {
        s.push(x);
        return;
    }
    //recursive case
    int data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);

}


void reverseStack(stack<int> &s) {
    //base case
    if (s.empty()) {
        return;
    }
    //otherwise
    //pop out the top element and insert at the bottom of reversed smaller stack
    int x = s.top();
    s.pop();
    //recursively reverse the smaller stack
    reverseStack(s);
    insertAtBottom(s, x);
}

int main() {
    stack<int> s;
    int n;
    cin >> n;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        s.push(k);
    }
    reverseStack(s);
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}


