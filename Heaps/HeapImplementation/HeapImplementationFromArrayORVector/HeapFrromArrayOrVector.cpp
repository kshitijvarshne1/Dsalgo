/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 07-Nov-20
*   Time: 6:53 PM
*   File: HeapFrromArrayOrVector.cpp
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

//Time Complexity-> O(N Log N)
void buildHeap(vector<int> &v) {
    for (int i = 1; i < v.size(); i++) {
        int idx = i;
        int parent = (i - 1) / 2;
        while (idx > 0 and v[idx] > v[parent]) {    //for maxheap -> v[idx]>v[parent]   /for minheap -> v[idx]<v[parent]
            swap(v[idx], v[parent]);
            idx = parent;
            parent = (parent - 1) / 2;
        }
    }
}

/*
void buildHeapUsingIndexEqualto1(vector<int> &v) {
    for (int i = 2; i < v.size(); i++) {
        int idx = i;
        int parent = i / 2;
        while (idx > 1 and v[idx] > v[parent]) {    //for maxheap -> v[idx]>v[parent]   /for minheap -> v[idx]<v[parent]
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}

Input:- -1,10,20,5,6,1,8,9,4
Output:- -1 20 10 9 6 1 5 8 4
*/
int main() {
    vector<int> v{10, 20, 5, 6, 1, 8, 9, 4};
    buildHeap(v);
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