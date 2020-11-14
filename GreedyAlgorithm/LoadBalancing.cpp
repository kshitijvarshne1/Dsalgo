/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 15-Nov-20
*   Time: 12:54 AM
*   File: LoadBalancing.cpp
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
/*
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 14-Nov-20
*   Time: 10:56 PM
*   File: gg.cpp
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

//Load Balancing
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int load = 0, diff = 0, max_load = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            load += a[i];
        }
        if (load % n != 0) {
            cout << "-1";
        } else {
            //find the load that is to be divided equally
            load = load / n;
            //greedy step
            for (int i = 0; i < n; i++) {
                //find the difference between final load to be assigned and current load
                diff += a[i] - load;
                int ans = abs(diff);
                max_load = max(max_load, ans);
            }
            cout << max_load;

        }

    }

    return 0;
}
