/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 11-Dec-20
*   Time: 10:57 PM
*   File: 1stApproachNaive.cpp
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

# define modValue 1e9 + 7
# define ll long long int
using namespace std;


int MatrixChainOrder(int p[], int i, int j) {
    if (i == j) {
        return 0;
    }
    int k;
    int min = INT_MAX;
    int count;

    for (k = i; k < j; k++) {
        count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }

    return min;
}

int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    */
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, 1, n - 1);

    return 0;
}