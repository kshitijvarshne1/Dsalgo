/*  
*   Created by Clion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Oct-20
*   Time: 6:58 PM
*   File: squareRoot.cpp
*/
# include<iostream>
# include<climits>
# include<algorithm>
# include <iomanip>

using namespace std;

int main() {
    float ans = 0;
    float inc = 1.0;
    int n, p;
    cin >> n >> p;
    for (int t = 0; t <= p; t++) {
        while (ans * ans <= n) {
            ans = ans + inc;
        }
        ans = ans - inc;
        inc = inc / 10;
    }
    cout << ans;
    return 0;
}

