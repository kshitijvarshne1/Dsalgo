/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 14-Nov-20
*   Time: 7:38 PM
*   File: BiasedStanding.cpp
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
//Baised standing
//find badness of rank for the teams
int main() {
    int t;
    cin >> t;
    int arr[10000] = {0};
    while (t--) {
        memset(arr, 0, sizeof(arr));
        int n;
        cin >> n;
        string name;
        int rank;
        for (int i = 0; i < n; i++) {
            cin >> name >> rank;
            arr[rank]++;
        }
        //Greedy Approach- assign the team nearest rank available
        int actual_rank = 1, sum = 0;
        for (int i = 1; i <= n; i++) {
            while (arr[i]) {
                sum += abs(actual_rank - i);
                arr[i]--;
                actual_rank++;
            }
        }
        cout << sum << endl;
    }

    return 0;
}