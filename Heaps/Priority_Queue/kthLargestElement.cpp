/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 09-Nov-20
*   Time: 12:16 AM
*   File: kthLargestElement.cpp
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

//find kth largest smallest element from the array
int kthlargestElement(int a[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq; //minHeap
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
    cout << kthlargestElement(a, n, k);
}