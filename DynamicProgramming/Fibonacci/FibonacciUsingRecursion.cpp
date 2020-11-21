/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 21-Nov-20
*   Time: 10:26 PM
*   File: FibonacciUsingRecursion.cpp
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
int nthFib(int n) {
    //Base case
    if (n == 0 or n == 1) {
        return n;
    }
    int ans;
    ans = nthFib(n - 1) + nthFib(n - 2);
    return ans;
}

int main() {
    cout << nthFib(6);

    return 0;
}
