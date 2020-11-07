/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 08-Nov-20
*   Time: 12:26 AM
*   File: kSmallestElement.cpp
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
//find k smallest element from the array

int main() {
    priority_queue<int> pq; //By default priority_queue like as maxHeap
    int n;
    cin >> n;
    int k;
    cin >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}