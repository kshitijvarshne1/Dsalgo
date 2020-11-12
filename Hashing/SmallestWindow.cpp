/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 12-Nov-20
*   Time: 2:28 PM
*   File: SmallestWindow.cpp
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
string find_window(string s, string p) {
    int SL = s.length();
    int PL = p.length();
    //1.Corner case
    if (PL > SL) {
        return "None";
    }
    //2.Frequency map
    int FS[256] = {0}; //frequency table of string s
    int FP[256] = {0}; //frequency table of string p

    for (int i = 0; i < PL; i++) {
        char ch = p[i];
        FP[ch]++;
    }
    //3. Sliding window(Expansion & contraction )+ update the min length window
    int cnt = 0;
    int start = 0;
    int min_length = INT_MAX;
    int start_idx = -1;
    for (int i = 0; i < SL; i++) {
        char ch = s[i];
        FS[ch]++;
        //Maintain the cnt of character metched
        if (FP[ch] != 0 and FS[ch] <= FP[ch]) {
            cnt++;
        }
        //if all the charaters match
        if (cnt == PL) {
            // start shrinking the window
            char temp = s[start];
            //Loop to remove un-wanted characters
            while (FP[temp] == 0 or FS[temp] > FP[temp]) {
                FS[temp]--;
                start++;
                temp = s[start];
            }
            //Window Size
            int window_length = i - start + 1;
            if (window_length < min_length) {
                min_length = window_length;
                start_idx = start;
            }
        }
    }
    if (start_idx == -1) {
        return "None";
    }
    string ans = s.substr(start_idx, min_length);
    return ans;
}

int main() {
    string s, p;
    cin >> s;
    cin >> p;
    cout << find_window(s, p);


    return 0;
}