/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 01-Nov-20
*   Time: 7:41 PM
*   File: BalancedParenthesis.cpp
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

bool isValidExpression(char *str) {
    stack<char> s;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty() or s.top() != '(') {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main() {   // This program for ->this type of parenthesis --> '('    -->>')'
    char s[100];
    cin >> s;
    if (isValidExpression(s)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}


