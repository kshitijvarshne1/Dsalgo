/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 02-Nov-20
*   Time: 12:24 AM
*   File: StockSpan.cpp
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

using namespace std;

void stockSpan(int prices[], int n, int span[]) {
    stack<int> s;
    s.push(0);
    span[0] = 1;
    //loop for the rest element
    for (int i = 0; i < n; i++) {
        int currentPrice = prices[i];
        //topmost element that is higher than the current prices
        while (!s.empty() and prices[s.top()] <= currentPrice) {
            s.pop();
        }
        if (!s.empty()) {
            int prev_highest = s.top();
            span[i] = i - prev_highest;
        } else {
            span[i] = i + 1;
        }
        //push this element into the stack
        s.push(i);
    }
}

int main() {
    int n;
    cin >> n;
    int prices[1000];
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    int span[1000] = {0};
    stockSpan(prices, n, span);
    for (int i = 0; i < n; i++) {
        cout << span[i] << " ";
    }
    cout << "END";


    return 0;
}


