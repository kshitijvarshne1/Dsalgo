/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 11-Nov-20
*   Time: 10:11 PM
*   File: LengthOfLongestSubarrayWithKSum.cpp
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
int lengthOfLongestSubarrayKSum(int a[], int n, int k) {
    unordered_map<int, int> m;
    int prefixSum = 0;
    int len = 0;
    for (int i = 0; i < n; i++) {
        prefixSum += a[i];
        if (prefixSum == k) {
            len = max(len, i + 1);
        }
        if (m.find(prefixSum - k) != m.end()) {
            len = max(len, i - m[prefixSum - k]);
        } else {
            //store the first occurence
            m[prefixSum] = i;
        }
    }
    return len;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << lengthOfLongestSubarrayKSum(a, n, k);
    return 0;
}

