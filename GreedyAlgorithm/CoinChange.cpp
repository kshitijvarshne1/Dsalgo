/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 14-Nov-20
*   Time: 1:07 PM
*   File: CoinChange.cpp
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

int make_change(int *coins, int n, int money) {
    int ans = 0;
    while (money > 0) {
        int idx = upper_bound(coins, coins + n, money) - 1 - coins;
        cout << coins[idx] << " ";
        money = money - coins[idx];
        ans++;
    }
    return ans;
}

int main() {
    int money;
    cin >> money;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int t = sizeof(coins) / sizeof(int);
    int totalCoins = make_change(coins, t, money);
    cout << endl;
    cout << "Total coins is " << totalCoins;
    return 0;
}
