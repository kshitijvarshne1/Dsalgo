/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 11-Nov-20
*   Time: 9:14 PM
*   File: LengthOfLongestSubarraySumZero.cpp
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

int lengthOfLongestSubarraySumOfZero(int a[], int n) {
    unordered_map<int, int> m;
    int prefixSum = 0;
    int len = 0;
    for (int i = 0; i < n; i++) {
        prefixSum += a[i];
        if (prefixSum == 0) {
            len = max(len, i + 1);
        }
        if (m.find(prefixSum) != m.end()) {
            len = max(len, i - m[prefixSum]);
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
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << lengthOfLongestSubarraySumOfZero(a, n);
    return 0;
}

