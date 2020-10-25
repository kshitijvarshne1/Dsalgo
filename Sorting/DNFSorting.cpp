/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 25-Oct-20
*   Time: 3:51 PM
*   File: DNFSorting.cpp
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

void dnfSort(int a[], int n) {
    //DNF:- Dutch National Flag
    //Sort array of 0s 1, 2s
    int lo = 0;
    int hi = n - 1;
    int mid = 0;
    while (mid <= hi) {
        if (a[mid] == 0) {
            swap(a[mid], a[lo]);
            lo++;
            mid++;
        } else if (a[mid] == 1) {
            mid++;
        } else if (a[mid] == 2) {
            swap(a[mid], a[hi]);
            hi--;
        }
    }
    return;
}

int main() {
    int a[] = {1, 0, 1, 1, 2, 2, 2, 0, 0, 1, 0, 1, 2};
    int n = sizeof(a) / sizeof(int);
    dnfSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

