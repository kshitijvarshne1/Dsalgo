c/*
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 08-Nov-20
*   Time: 7:29 PM
*   File: KClosestNumber.cpp
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
//k Closest Numbers
int main() {
    priority_queue<pair<int, int>> pq; //By default priority_queue like as maxHeap //for minHeap we use  priority_queue<int,vector<int>,greater<int>>pq;
    pair<int, int> temp;
    int n;
    cin >> n;
    int x, k;
    cin >> x >> k;
    for (int j = 0; j < n; j++) {
        int num;
        cin >> num;
        temp = make_pair(abs(num - x), num);
        pq.push(temp);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    while (pq.size() > 0) {
        cout << pq.top().second << " ";
        pq.pop();
    }
}
