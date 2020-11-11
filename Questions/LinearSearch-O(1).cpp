/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 12-Nov-20
*   Time: 12:22 AM
*   File: LinearSearch.cpp
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_set<int> m;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            m.insert(k);
        }
        int q;
        cin >> q;
        while (q--) {
            int x;
            cin >> x;
            if (m.find(x) != m.end()) {
                cout << "Yes" << endl;

            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;


}

