/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Nov-20
*   Time: 3:34 PM
*   File: MaximumSubarraySumSpaceOptimise.cpp
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
//Using Dp->Bottom up ->Space Optimise ->{ Kadane's algo }

int maxSum(int a[], int n) {
    int currentSUm = 0;
    int maxSoFar = 0;
    for (int i = 0; i < n; i++) {
        currentSUm = currentSUm + a[i];
        if (currentSUm < 0) {
            currentSUm = 0;
        }
        maxSoFar = max(currentSUm, maxSoFar);
    }
    return maxSoFar;
}

int main() {
    int a[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    int n = sizeof(a) / sizeof(int);
    cout << maxSum(a, n);
    return 0;
}