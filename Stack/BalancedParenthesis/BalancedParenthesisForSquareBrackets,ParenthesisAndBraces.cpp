/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 01-Nov-20
*   Time: 7:56 PM
*   File: BalancedParenthesisForSquareBrackets.cpp
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
    char popch;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == '(' or ch == '{' or ch == '[') {
            s.push(ch);
        } else if (ch == ')' or ch == '}' or ch == ']') {
            if (s.empty()) {
                return false;
            } else {
                switch (ch) {
                    case ')':    //for closing parenthesis, pop it and check for braces and square brackets
                        popch = s.top();
                        s.pop();
                        if (popch == '{' || popch == '[')
                            return false;
                        break;
                    case '}': //for closing braces, pop it and check for parenthesis and square brackets
                        popch = s.top();
                        s.pop();
                        if (popch == '(' || popch == '[')
                            return false;
                        break;
                    case ']': //for closing square bracket, pop it and check for braces and parenthesis
                        popch = s.top();
                        s.pop();
                        if (popch == '(' || popch == '{')
                            return false;
                        break;
                }
            }

        }
    }
    return s.empty();
}

int main() {
    // This program for square brackets , parenthesis and braces
    char s[100];
    cin >> s;
    if (isValidExpression(s)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}

