/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 15-Nov-20
*   Time: 12:56 AM
*   File: DefenseOfAKingdom.cpp
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

//Defense of a kingdom
using namespace std;

int main() {
    int n;
    cin >> n;
    int width = 15, height = 8;
    int x[n], y[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    //sorting
    sort(x, x + n);
    sort(y, y + n);
//    int dx=0;
//    int dy=0;
    int dx = x[0];
    int dy = y[0];
    for (int i = 1; i < n; i++) {
        dx = max(dx, x[i] - x[i - 1]);
        dy = max(dy, y[i] - y[i - 1]);
    }
    //corner case
    // dx=max(dx,width-x[n-1]);
    // dy=max(dy,height-y[n-1]);
    // cout<<dx*dy;
    cout << (dx - 1) * (dy - 1);
    return 0;
}

