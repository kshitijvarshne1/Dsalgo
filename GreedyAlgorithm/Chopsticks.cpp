/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 15-Nov-20
*   Time: 11:11 AM
*   File: Chopsticks.cpp
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
//Chopsticks
int main() {
    int n, d;
    cin >> n;
    cin >> d;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int c = 0;
    int i = 0;
    n = n - 1;
    while (n--) {
        if (a[i + 1] - a[i] >= d) {
            c++;
            i = i + 2;
        } else {
            i = i + 1;
        }
    }
    cout << "No of chopsticks made:- " << c;

    return 0;
}
