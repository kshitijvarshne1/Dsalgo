/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 03-Nov-20
*   Time: 12:03 AM
*   File: ImplementAStackUsing2Queue.cpp
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
# include<queue>

using namespace std;

template<typename T>
class Stack {
    queue<T> q1, q2;
public:
    void push(T x) {
        q1.push(x);
    }

    void pop() {
        //remove the last add element from q1
        //we have to move first n-1 element in q2
        //interchange the names of q1 and q2
        if (q1.empty()) {
            return;
        }
        while (q1.size() > 1) {
            T element = q1.front();
            q2.push(element);
            q1.pop();
        }
        //Remove the last element
        q1.pop();
        //swap the names of q1 and q2
        swap(q1, q2);

    }

    int top() {
        while (q1.size() > 1) {
            T element = q1.front();
            q2.push(element);
            q1.pop();
        }
        //1 element in q1
        T element = q1.front();
        q1.pop();
        q2.push(element);

        swap(q1, q2);
        return element;
    }

    int size() {
        return q1.size() + q2.size();
    }

    bool empty() {
        return size() == 0;
    }
};

int main() {
    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}


