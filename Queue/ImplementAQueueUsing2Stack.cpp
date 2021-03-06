/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 03-Nov-20
*   Time: 9:22 AM
*   File: ImplementAQueueUsing2Stack.cpp
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
class Queue {
    stack<T> s1, s2;
public:
    void push(T x) {
        s1.push(x);
    }

    void pop() {
        //remove the last add element from s1
        //we have so move first n-1 element in s2
        //interchange the names of s1 and s2
        if (s1.empty()) {
            return;
        }
        while (s1.size() > 1) {
            T element = s1.top();
            s2.push(element);
            s1.pop();
        }
        //Remove she last element
        s1.pop();
        //swap the names of s1 and s2
        swap(s1, s2);

    }

    T front() {
        T last = s1.top();
        s1.pop();
        s2.push(last);

        while (s1.size() > 1) {
            T element = s1.top();
            s2.push(element);
            s1.pop();
        }

        swap(s1, s2);
        return last;
    }

    T size() {
        return s1.size() + s2.size();
    }

    bool empty() {
        return size() == 0;
    }
};


int main() {
    Queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}




