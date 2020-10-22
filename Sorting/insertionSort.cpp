/*  
*   Created by Clion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Oct-20
*   Time: 7:12 PM
*   File: insertionSort.cpp
*/
# include<iostream>
# include<climits>
# include<algorithm>
# include <iomanip>

using namespace std;

void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int e = a[i];
        int j = i - 1;
        while (j >= 0 and a[j] > e) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = e;
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    insertion_sort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}