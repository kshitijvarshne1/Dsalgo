/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 05-Dec-20
*   Time: 12:27 AM
*   File: CountSort.cpp
*/
# include<iostream>
# include<bits/stdc++.h>
# include<climits>
# include<cmath>
# include<algorithm>
# include<cstring>
# include<iomanip>
# include<vector>
# include<stack>
# include<queue>
# include<map>
# include<unordered_map>
# include<unordered_set>

# define modValue 1e9 + 7
# define ll long long int
using namespace std;

void countSort(int a[], int n) {
    int k = a[0];
    for (int i = 0; i < n; ++i) {
        k = max(k, a[i]);
    }

    int count[10000] = {0};
    for (int i = 0; i < n; ++i) {
        count[a[i]]++;
    }
    for (int i = 0; i <= k; ++i) {
        count[i] += count[i - 1];
    }
    int output[10000];
    for (int i = n - 1; i >= 0; i--) {
        output[--count[a[i]]] = a[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << output[i] << " ";
    }
}

int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    */
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    countSort(a, n);
    return 0;
}

