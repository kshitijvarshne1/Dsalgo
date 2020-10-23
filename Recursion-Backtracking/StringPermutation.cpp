/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 23-Oct-20
*   Time: 11:49 PM
*   File: StringPermutation.cpp
*/
# include<iostream>
# include<climits>
# include<algorithm>
# include<set>
# include<bits/stdc++.h>
# include<cstring>
# include<iomanip>

using namespace std;

void stringPermutation(char in[], int i, set<string> &s) {
    //Base case
    if (in[i] == '\0') {
        //cout << in << endl;
        string t(in);
        s.insert(t);
        return;
    }
    //Recursive case
    for (int j = i; in[j] != '\0'; j++) {
        swap(in[i], in[j]);
        stringPermutation(in, i + 1, s);
        //Backtracking
        swap(in[i], in[j]);
    }
    return;
}

int main() {
    char in[100];
    cin >> in;
    set<string> s;
    stringPermutation(in, 0, s);
    for (auto str : s) {
        cout << str << endl;
    }
    return 0;
}

