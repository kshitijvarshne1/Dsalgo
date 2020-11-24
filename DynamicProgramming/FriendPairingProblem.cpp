/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 24-Nov-20
*   Time: 8:33 PM
*   File: FriendPairingProblem.cpp
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

using namespace std;

int countFriendsPairings(int n) {
    int dp[n + 1];
    for (int i = 0; i <= n; i++) {
        if (i <= 2)
            dp[i] = i;
        else
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
    return dp[n];
}


int main() {
    int n;
    cin >> n;
    cout << countFriendsPairings(n);

    return 0;
}
