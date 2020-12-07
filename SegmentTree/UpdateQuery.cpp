/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 07-Dec-20
*   Time: 11:11 PM
*   File: UpdateQuery.cpp
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

void updateRec(int segmentStart, int segmentEnd, int i, int treeIndex, int diff, int tree[]) {
    if (i < segmentStart || i > segmentEnd)
        return;

    tree[treeIndex] = tree[treeIndex] + diff;

    if (segmentEnd > segmentStart) {
        int mid = (segmentStart + segmentEnd) / 2;

        updateRec(segmentStart, mid, i, 2 * treeIndex + 1, diff, tree);
        updateRec(mid + 1, segmentEnd, i, 2 * treeIndex + 2, diff, tree);

    }
}

int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    */
    int arr[] = {10, 20, 30, 40}, n = 4;

    int tree[4 * n];
    CST(0, n - 1, 0, arr, tree);

    updateRec(0, 3, 1, 0, 5, tree);

    return 0;
}