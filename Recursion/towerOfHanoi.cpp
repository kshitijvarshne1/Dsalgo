/*  
*   Created by IntelliJ IDEA.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Oct-20
*   Time: 6:49 PM
*   File: towerOfHanoi.cpp
*/
# include<iostream>
# include<climits>
# include<algorithm>
# include <iomanip>

using namespace std;

void move(int n, char src, char helper, char dest) {
    if (n == 0) {
        return;
    }
    move(n - 1, src, dest, helper);
    cout << "Moving ring " << n << " from " << src << " to " << dest << endl;
    move(n - 1, helper, src, dest);
}

int main() {
    int n;
    cin >> n;
    move(n, 'A', 'C', 'B');
    return 0;
}
