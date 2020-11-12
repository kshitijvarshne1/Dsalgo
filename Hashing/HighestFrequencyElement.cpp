/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 12-Nov-20
*   Time: 7:38 PM
*   File: HighestFrequencyElement.cpp
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
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[a[i]]++;
    }
    int num = a[0];
    int maxfre = 0;
    for (int i = 0; i < n; i++) {
        if (m.find(a[i])->second > maxfre) {
            maxfre = m.find(a[i])->second;
            num = m.find(a[i])->first;
        }
    }
    cout << num;


    return 0;
}
