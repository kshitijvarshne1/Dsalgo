/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Oct-20
*   Time: 9:07 PM
*   File: twoPointer.cpp
*/
# include<iostream>
# include<climits>
# include<algorithm>
# include<bits/stdc++.h>
# include<cstring>
# include<iomanip>

using namespace std;

void twoPointer(int a[], int n, int key) {
    int i = 0;
    int j = n - 1;
    while (i < j) {
        int currentSum = a[i] + a[j];
        if (currentSum > key) {
            j--;
        } else if (currentSum < key) {
            i++;
        } else {
            cout << a[i] << " and " << a[j] << endl;
            i++;
            j--;
        }
    }
    return;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int key;
    cin >> key;
    sort(a, a + n);
    twoPointer(a, n, key);
    return 0;
}


