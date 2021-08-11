/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 11-Aug-21
*   Time: 4:56 PM
*   File: BuildAndSumQuery.cpp
*/
# include<bits/stdc++.h>
# include<iostream>
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

# define modValue 1e9 + 7
# define ll long long int
//# define cin ios_base::sync_with_stdio(false);cin.tie(NULL); cin
using namespace std;

int seg[4 * 105];

void build(int ind, int l, int h, vector<int> &nums) {
    if (l == h) {
        seg[ind] = nums[l];
        return;
    }

    int mid = l + (h - l) / 2;
    build(2 * ind + 1, l, mid, nums);
    build(2 * ind + 2, mid + 1, h, nums);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}


int sumQuery(int ind, int low, int high, int l, int r) {
    if (low >= l and high <= r) {
        return seg[ind];
    }
    if (high < l or low > r) return 0;

    int mid = low + (high - low) / 2;


    int left = sumQuery(2 * ind + 1, low, mid, l, r);
    int right = sumQuery(2 * ind + 2, mid + 1, high, l, r);

    return left + right;
}


int main() {


    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        nums.push_back(k);
    }
    build(0, 0, n - 1, nums);

    int left = 2;
    int right = 3;
    cout << sumQuery(0, 0, n - 1, left, right);


    return 0;
}
