/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 07-Dec-20
*   Time: 10:22 PM
*   File: RangeQuery.cpp
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
using namespace std;

int CST(int segmentStart, int segmentEnd, int treeIndex, int arr[], int tree[]) {
    if (segmentStart == segmentEnd) {
        tree[treeIndex] = arr[segmentStart];
        return arr[segmentStart];
    }

    int mid = (segmentStart + segmentEnd) / 2;

    tree[treeIndex] = CST(segmentStart, mid, 2 * treeIndex + 1, arr, tree)
                      + CST(mid + 1, segmentEnd, 2 * treeIndex + 2, arr, tree);

    return tree[treeIndex];
}

int getSumRec(int queryStart, int queryEnd, int segmentStart, int segmentEnd, int treeIndex, int tree[]) {
    if (segmentEnd < queryStart || segmentStart > queryEnd)
        return 0;
    if (queryStart <= segmentStart && queryEnd >= segmentEnd)
        return tree[treeIndex];

    int mid = (segmentStart + segmentEnd) / 2;

    return getSumRec(queryStart, queryEnd, segmentStart, mid, 2 * treeIndex + 1, tree)
           + getSumRec(queryStart, queryEnd, mid + 1, segmentEnd, 2 * treeIndex + 2, tree);
}


int main() {
    /*ios_base::sync_with_stdio(false);
   cin.tie(NULL);cout.tie(NULL);
   */

    int arr[] = {10, 20, 30, 40}, n = 4;

    int tree[4 * n];
    CST(0, n - 1, 0, arr, tree);

    cout << getSumRec(0, 2, 0, 3, 0, tree);
    return 0;
}


