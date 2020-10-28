/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 28-Oct-20
*   Time: 10:51 AM
*   File: Kadane.cpp
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
    int n, a[1000];
    int maxSum = 0;
    int left = -1;
    int right = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int currentSum = 0;
            for (int k = i; k <= j; k++) {
                currentSum += a[k];
            }
            if (maxSum < currentSum) {
                maxSum = currentSum;
                left = i;
                right = j;
            }
        }
    }
    cout << "Max Sum:-- " << maxSum << endl;
    for (int i = left; i <= right; i++) {
        cout << a[i] << ", ";
    }
    return 0;
}

