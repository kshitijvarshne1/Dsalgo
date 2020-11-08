/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 08-Nov-20
*   Time: 11:23 PM
*   File: SortingAccToTheirFrequency.cpp
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

//Sorting according to their frequency
void SortingAccToTheirFrequency(priority_queue<pair<int, int>> pq, int arr[], int n) {
    unordered_map<int, int> mp;//use to count frequency //hash table
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }
    for (auto x : mp) {
        pq.push(make_pair(x.second, x.first));
    }
    while (pq.size() > 0) {
        int fre = pq.top().first;
        int ele = pq.top().second;
        while (fre--) {
            cout << ele << " ";
        }
        pq.pop();
    }
}

int main() {
    priority_queue<pair<int, int>> pq;
    int n;
    cin >> n;
    int a[n];
    for (int j = 0; j < n; j++) {
        cin >> a[j];
    }
    SortingAccToTheirFrequency(pq, a, n);
    return 0;
}

