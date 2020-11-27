/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 27-Nov-20
*   Time: 11:00 PM
*   File: MaxSumSubmatrixInRowAndColumnSorted2dMatrix.cpp
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
using namespace std;

int maxSumOfSubmatrices(int a[][100], int m, int n) {
    //col wise add addition
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            a[i][j] += a[i][j + 1];
        }
    }
    //Row wise addition
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 2; j >= 0; j--) {
            a[j][i] += a[j + 1][i];
        }
    }


    int result = INT_MIN;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result = max(result, a[i][j]);
        }
    }
    return result;
}


int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    */
    int m, n;
    cin >> m >> n;
    int a[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << maxSumOfSubmatrices(a, m, n);

    return 0;
}
