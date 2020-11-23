
/*
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 23-Nov-20
*   Time: 7:36 PM
*   File: RodCuttingProblemRecursionBased.cpp
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

int maxProfit(int prices[], int n) {
    if (n <= 0) {
        return 0;
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        int cut = i + 1;
        int currentAns = prices[i] + maxProfit(prices, n - cut);
        ans = max(currentAns, ans);
    }
    return ans;
}

int main() {
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices) / sizeof(int);
    cout << maxProfit(prices, n);

    return 0;
}
