/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 11-Nov-20
*   Time: 8:16 PM
*   File: CheckSumOfSubarrayIsZeroOrNot.cpp
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

bool checkSumOfSubarrayIsZeroOrNot(int a[], int n) {
    unordered_set<int> s;
    int prefixSum = 0;
    for (int i = 0; i < n; i++) {
        prefixSum += a[i];
        //check if sum is already 0 OR sum was present in the set
        if (prefixSum == 0 or s.find(prefixSum) != s.end()) {
            return true;
        }
        s.insert(prefixSum);
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (checkSumOfSubarrayIsZeroOrNot(a, n)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}

