/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 07-Dec-20
*   Time: 9:53 PM
*   File: BuiltSegmentTree.cpp
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

int constructSegmentTree(int segmentStart, int segmentEnd, int treeIndex, int arr[], int tree[]) {
    if (segmentStart == segmentEnd) {
        tree[treeIndex] = arr[segmentStart];
        return arr[segmentStart];
    }

    int mid = (segmentStart + segmentEnd) / 2;

    tree[treeIndex] = constructSegmentTree(segmentStart, mid, 2 * treeIndex + 1, arr, tree)
                      + constructSegmentTree(mid + 1, segmentEnd, 2 * treeIndex + 2, arr, tree);

    return tree[treeIndex];
}

int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    */
    int arr[] = {10, 20, 30, 40}, n = 4;
    int tree[4 * n];
    cout << constructSegmentTree(0, n - 1, 0, arr, tree) << endl;
    return 0;
}
