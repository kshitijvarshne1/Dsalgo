/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 12-Nov-20
*   Time: 7:28 PM
*   File: Arrays.cpp
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
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[a[i]]++;
    }
    int newArr[10000];
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (m.find(b[i]) != m.end()) {
            if (m.find(b[i])->second > 0) {
                newArr[c] = b[i];
                c = c + 1;
                int temp = m.find(b[i])->second;
                temp -= 1;
                m.erase(b[i]);
                m[b[i]] = temp;
            }
        }
    }
    sort(newArr, newArr + c);
    for (int i = 0; i < c; i++) {
        cout << newArr[i] << " ";
    }
    return 0;
}
