/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 08-Nov-20
*   Time: 11:57 PM
*   File: JoinTheRopes.cpp
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

//Join the ropes
using namespace std;
int joinTheRopes(priority_queue<int, vector<int>, greater<int>> pq) {
    int cost = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int newrope = a + b;
        cost += newrope;
        pq.push(newrope);
    }
    return cost;
}

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;   //minHeap
    int n, k;
    cin >> n;
    for (int j = 0; j < n; j++) {
        cin >> k;
        pq.push(k);
    }
    cout << joinTheRopes(pq);
    return 0;
}