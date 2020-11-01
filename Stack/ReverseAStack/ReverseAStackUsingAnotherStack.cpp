/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 01-Nov-20
*   Time: 4:55 PM
*   File: ReverseAStackUsingAnotherStack.cpp
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

void transfer(stack<int> &s1, stack<int> &s2, int n) {
    for (int i = 0; i < n; i++) {
        s2.push(s1.top());
        s1.pop();
    }
}

void reverseStack(stack<int> &s1) {
    //helper stack
    stack<int> s2;
    int n = s1.size();
    for (int i = 0; i < n; i++) {
        //pick the element at top & insert it at the bottom
        int x = s1.top();
        s1.pop();
        //transfer n-i-1 element from stack s1 into s2
        transfer(s1, s2, n - i - 1);
        //insert the element x in s1
        s1.push(x);
        //transfer n-i-1 element from stack s2 into s1
        transfer(s2, s1, n - i - 1);
    }
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


