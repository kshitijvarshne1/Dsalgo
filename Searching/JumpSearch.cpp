/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 24-Jan-21
*   Time: 11:33 PM
*   File: JumpSearch.cpp
*/
# include<iostream>
# include<bits/stdc++.h>
# include<climits>
# include<cmath>
# include<algorithm>
# include<cstring>
# include<iomanip>
# include<vector>
# include<stack>
# include<queue>
# include<map>
# include<unordered_map>
# include<unordered_set>

# define modValue 1e9 + 7
# define ll long long int
# define cin ios_base::sync_with_stdio(false);cin.tie(NULL); cin
using namespace std;

int jumpSearch(int arr[], int x, int n) {
    int step = sqrt(n);
    int prev = 0;
    //The while loop is used to find the block in which element is present
    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }
    // This while loop is used to find the index nearest to the element and if not then simply return -1
    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n))
            return -1;
    }
    if (arr[prev] == x) {
        return prev;
    }
    return -1;
}

int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    */
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    //Sorted array is required if not then sort it
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = jumpSearch(arr, x, n);
    cout << "\nNumber " << x << " is at index " << index;

    return 0;
}

