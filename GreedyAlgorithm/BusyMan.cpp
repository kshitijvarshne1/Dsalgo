/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 14-Nov-20
*   Time: 1:57 PM
*   File: BusyMan.cpp
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

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        int s, e;
        for (int i = 0; i < n; i++) {
            cin >> s >> e;
            v.push_back(make_pair(s, e));
        }
        //Activity selection algorithm
        //Sort
        sort(v.begin(), v.end(), compare);
        //start picking activities
        int result = 1;
        int recentActivity = v[0].second;
        //iterate over remaining activities
        for (int i = 1; i < n; i++) {
            if (v[i].first >= recentActivity) {
                recentActivity = v[i].second;
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
