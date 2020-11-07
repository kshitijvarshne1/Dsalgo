/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 08-Nov-20
*   Time: 12:51 AM
*   File: SortKSortedArray.cpp
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
//Sort the K sorted array

int main() {
    priority_queue<int, vector<int>, greater<int>> pq; //By default priority_queue like as maxHeap //for minHeap we use  priority_queue<int,vector<int>,greater<int>>pq;
    vector<int> final;
    int n;
    cin >> n;
    int k;
    cin >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
        if (pq.size() > k) {
            final.push_back(pq.top());
            pq.pop();
        }
    }
    while (!pq.empty()) {
        final.push_back(pq.top());
        pq.pop();
    }
    for (auto i = final.begin(); i != final.end(); i++) {
        cout << *i << " ";
    }

}