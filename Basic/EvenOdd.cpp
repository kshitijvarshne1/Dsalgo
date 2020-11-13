/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 13-Nov-20
*   Time: 11:32 PM
*   File: EvenOdd.cpp
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
// find odd and even using LSB bit of given number <- Reduces modulo complexity
/*
if n&1 ==1  <- odd
if n&1 ==0  <- even
 */
/*
if n=1 <- result is 1
if n=0 <- result is 0
*/

bool evenOdd(int n) {
    return (n & 1);
}

int main() {
    int n;
    cin >> n;
    if (evenOdd(n)) {
        cout << "It is a odd number";
    } else {
        cout << "It is a even number";
    }
    return 0;
}
