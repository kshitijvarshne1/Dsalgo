/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 25-Oct-20
*   Time: 9:27 PM
*   File: WaveSort.cpp
*/
# include<iostream>
# include<climits>
# include<cmath>
# include<algorithm>
# include<bits/stdc++.h>
# include<cstring>
# include<iomanip>
# include<vector>

using namespace std;

int main() {
    int a[] = {1, 3, 4, 2, 7, 8};
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n; i += 2) {
        //Pre element
        if (i != 0 and a[i] < a[i - 1]) {
            swap(a[i], a[i - 1]);
        }
        //next element
        if (i != (n - 1) and a[i] < a[i + 1]) {
            swap(a[i], a[i + 1]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

