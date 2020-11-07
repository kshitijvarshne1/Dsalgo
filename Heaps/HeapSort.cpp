/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 07-Nov-20
*   Time: 10:53 PM
*   File: HeapSort.cpp
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

void heapify(vector<int> &v, int idx, int size) {
    int left = 2 * idx;
    int right = left + 1;

