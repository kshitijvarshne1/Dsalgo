/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 09-Nov-20
*   Time: 12:12 AM
*   File: kthSmallestElement.cpp
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

//find kth smallest element from the array
int kthSmallestElement(int a[], int n, int k) {
    priority_queue<int> pq; //maxHeap
    for (int i = 0; i < n; i++) {
        pq.push(a[i]);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    return pq.top();
}

int main() {

    int n;
    cin >> n;
    int k;
    cin >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << kthSmallestElement(a, n, k);
}