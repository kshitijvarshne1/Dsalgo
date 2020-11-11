/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 12-Nov-20
*   Time: 12:05 AM
*   File: LongestSequenceOfConsecutiveNumbers.cpp
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
# include<map>
# include<unordered_map>
# include<unordered_set>

using namespace std;

int findLongestSequenceOfConsecutiveNumbers(int a[], int n) {
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(a[i]);
    }
    //iterate over all the element
    //target those from which a streak can start
    int max_streak = 1;
    for (int i = 0; i < n; i++) {
        if (s.find(a[i] - 1) == s.end()) {
            //a[i] is a starting point of streak
            // traverse the entire range that is contained is that streak
            int next_no = a[i] + 1;
            int streak_len = 1;
            while (s.find(next_no) != s.end()) {
                next_no += 1;
                streak_len += 1;
            }
            max_streak = max(max_streak, streak_len);
        }
    }
    return max_streak;
}


int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << findLongestSequenceOfConsecutiveNumbers(a, n);
    return 0;
}

