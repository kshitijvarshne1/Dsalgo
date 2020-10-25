/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 25-Oct-20
*   Time: 11:29 AM
*   File: QuickSortByRecursion.cpp
*/
# include<iostream>
# include<climits>
# include<cmath>
# include<algorithm>
# include<bits/stdc++.h>
# include<cstring>
# include<iomanip>

using namespace std;

int divide(int *a, int s, int e) {
    //Implace (can't take extra carry)
    int i = s - 1;
    int j = s;
    int pivot = a[e];
    for (; j <= e - 1;) {
        if (a[j] <= pivot) {
            i = i + 1;
            swap(a[i], a[j]);
        }
        j = j + 1;
    }
    //place the pivot element in the correct index
    swap(a[i + 1], a[e]);
    return i + 1;
}

void quickSort(int *a, int s, int e) {
    //Base Case
    if (s >= e) {
        return;
    }
    //Partition
    int p = divide(a, s, e);
    //Recursive case
    //left part
    quickSort(a, s, p - 1);
    //right part
    quickSort(a, p + 1, e);
}

int main() {
    int n;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

