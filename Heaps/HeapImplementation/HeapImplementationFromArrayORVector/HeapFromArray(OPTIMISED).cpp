/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 07-Nov-20
*   Time: 8:40 PM
*   File: HeapFromArray.cpp
*/
# include<iostream>
# include<climits>
# include<cmath>
# include<algorithm>
# include<bits/stdc++.h>
# include<cstring>
# include<iomanip>
# include<vector>
# include<stack>
# include<queue>

using namespace std;

//Time Complexity-> O(N)
void buildHeapOptimised(vector<int> &v) {
    for (int i = v.size() - 1; i >= 1; i--) {
        int idx = i;
        int parent = (i - 1) / 2;
        while (idx > 0 and v[idx] > v[parent]) {    //for maxheap -> v[idx]>v[parent]   /for minheap -> v[idx]<v[parent]
            swap(v[idx], v[parent]);
            idx = parent;
            parent = (parent - 1) / 2;
        }
    }
}

int main() {
    vector<int> v{10, 20, 5, 6, 1, 8, 9, 4};
    buildHeapOptimised(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
/*
Input:-
10, 20, 5, 6, 1, 8, 9, 4
Output:-
20 10 9 6 1 5 8 4
 */
