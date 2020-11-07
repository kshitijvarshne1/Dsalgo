/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 07-Nov-20
*   Time: 9:26 PM
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
bool minHeap = false;

bool compare(int a, int b) {
    if (minHeap) {
        return a < b;
    } else {
        return a > b;
    }
}

void heapify(vector<int> &v, int idx) {
    int left = 2 * idx;
    int right = left + 1;

    int min_idx = idx;
    int last = v.size() - 1;
    if (left <= last && compare(v[left], v[idx])) {
        min_idx = left;
    }
    if (right <= last && compare(v[right], v[min_idx])) {
        min_idx = right;
    }
    if (min_idx != idx) {
        swap(v[idx], v[min_idx]);
        heapify(v, min_idx);
    }
}

//Time Complexity-> O(N)
void buildHeapOptimised(vector<int> &v) {
    for (int i = (v.size() - 1) / 2; i >= 1; i--) {
        heapify(v, i);
    }
}

int main() {
    vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    buildHeapOptimised(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
/*
Input:-
-1, 10, 20, 5, 6, 1, 8, 9, 4
Output:-
-1 20 10 9 6 1 8 5 4
 */