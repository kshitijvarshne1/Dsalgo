/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 14-Nov-20
*   Time: 11:04 AM
*   File: Max_Xor_Pair_Value.cpp
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

class node {
public:
    node *left; //for 0
    node *right; //for 1
};

class trie {
    node *root;
public:
    trie() {
        root = new node();
    }

    //insert function
    //for 32 bit integer
    //MSB = bit = (n>>31)&1
    void insert(int n) {
        node *temp = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (bit == 0) {
                if (temp->left == NULL) {
                    temp->left = new node();
                }
                temp = temp->left;
            } else {
                //bit is 1
                if (temp->right == NULL) {
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
    }

    //helper function to find max Xor
    int max_xor_helper(int value) {
        int current_ans = 0;
        node *temp = root;
        for (int j = 31; j >= 0; j--) {
            int bit = (value >> j) & 1;
            if (bit == 0) {
                //find the complementary value
                if (temp->right != NULL) {
                    temp = temp->right;
                    current_ans += (1 << j);
                } else {
                    temp = temp->left;
                }
            } else {
                //curent bit is 1
                if (temp->left != NULL) {
                    temp = temp->left;
                    current_ans += (1 << j);
                } else {
                    temp = temp->right;
                }
            }
        }
        return current_ans;
    }

    int max_xor(int *input, int n) {
        int max_xor = 0;
        for (int i = 0; i < n; i++) {
            int val = input[i];
            insert(val);
            int current_xor = max_xor_helper(val);
            // cout << current_xor << " ";
            max_xor = max(current_xor, max_xor);
        }
        return max_xor;
    }

};

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    trie t;
    cout << t.max_xor(a, n) << endl;
    return 0;
}
/*
Input:-
6
3 10 5 25 2 8
Output:-
5^25=28
 */
