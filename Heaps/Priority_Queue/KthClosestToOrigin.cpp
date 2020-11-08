/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 09-Nov-20
*   Time: 12:49 AM
*   File: KthClosestToOrigin.cpp
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

//find kth closest to origin
void kthClosestToOrigin(int a[100][100], int n, int k) {
    priority_queue<pair<int, pair<int, int>>> pq;

    for (int i = 0; i < n; i++) {
        int x = a[i][0];
        int y = a[i][1];
        int dis = x * x + y * y;
        pq.push(make_pair(dis, make_pair(x, y)));
        if (pq.size() > k) {
            pq.pop();
        }
    }
    cout << pq.top().second.first << " " << pq.top().second.second;
}

int main() {

    int n;
    cin >> n;
    int k;
    cin >> k;
    int a[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }
    kthClosestToOrigin(a, n, k);
}