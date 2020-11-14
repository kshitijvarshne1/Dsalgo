/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 14-Nov-20
*   Time: 4:17 PM
*   File: ConnectingWires.cpp
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

int main() {
    int n;
    cin >> n;
    int whiteDotPossitionArray[n];
    int blackDotPossitionArray[n];
    for (int i = 0; i < n; i++) {
        cin >> whiteDotPossitionArray[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> blackDotPossitionArray[i];
    }
    sort(whiteDotPossitionArray, whiteDotPossitionArray + n);
    sort(blackDotPossitionArray, blackDotPossitionArray + n);
    int minLength = 0;
    for (int i = 0; i < n; i++) {
        minLength += abs(whiteDotPossitionArray[i] - blackDotPossitionArray[i]);
    }
    cout << "Minmum length of wire required to connect the dots:- " << minLength;
    return 0;
}