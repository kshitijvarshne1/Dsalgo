/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 12-Nov-20
*   Time: 10:08 PM
*   File: TotalLengthOfSubarrayOfDistinctElement.cpp
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
# include<map>
# include<unordered_map>
# include<unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    unordered_set<int> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n and m.find(a[j]) == m.end()) {
            m.insert(a[j]);
            j++;
        }
        ans += ((j - i) * (j - i + 1)) / 2;
        m.erase(a[i]);

    }
    cout << ans;


    return 0;
}
