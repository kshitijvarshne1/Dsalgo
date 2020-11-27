/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 27-Nov-20
*   Time: 9:45 PM
*   File: 3rdApproach.cpp
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

int sumOfSubmatrices(int a[][100], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int tl = (i + 1) * (j + 1);
            int br = (m - i) * (n - j);
            sum += a[i][j] * tl * br;
        }
    }
    return sum;
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
    cout << sumOfSubmatrices(a, m, n);

    return 0;
}