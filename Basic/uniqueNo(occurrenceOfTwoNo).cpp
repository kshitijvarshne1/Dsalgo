/*  
*   Created by IntelliJ IDEA.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Oct-20
*   Time: 6:40 PM
*   File: uniqueNo.cpp
*/
# include<iostream>
# include<climits>
# include<algorithm>
# include <iomanip>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    int s = 0;
    for (int j = 0; j < n; j++) {
        cin >> k;
        s = s ^ k;
    }
    cout << s;
    return 0;
}

