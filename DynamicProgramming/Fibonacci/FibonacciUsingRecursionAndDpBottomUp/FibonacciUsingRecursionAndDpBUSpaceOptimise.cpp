/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Nov-20
*   Time: 12:03 AM
*   File: FibonacciUsingRecursionAndDpBUSpaceOptimise.cpp
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

//nth fibonacci number using recursion and DP Time->O(n) Space-> o(1)
//Bottom up approach
int nthFib(int n) {
    if (n == 0 or n == 1) {
        return n;
    }
    int a = 0;
    int b = 1;
    int c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    cout << nthFib(n);
    return 0;
}
