/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 08-Nov-20
*   Time: 9:00 PM
*   File: TopKFrequentNumbers.cpp
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

//Top k frequent numbers
using namespace std;

void kFrequentNum(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq, int arr[], int n,
                  int k) {
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (auto x : mp) {
        pq.push(make_pair(x.second, x.first));
        if (pq.size() > k) {
            pq.pop();
        }
    }
    while (pq.size() > 0) {
        cout << pq.top().second << " ";
        pq.pop();
    }


}

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n;
    cin >> n;
    int a[n];
    int k;
    cin >> k;
    for (int j = 0; j < n; j++) {
        cin >> a[j];
    }
    kFrequentNum(pq, a, n, k);
    return 0;
}

