/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 26-Nov-20
*   Time: 5:23 PM
*   File: StringTrieInsertAndSearch.cpp
*/
# include<iostream>
# include<bits/stdc++.h>
# include<climits>
# include<cmath>
# include<algorithm>
# include<cstring>
# include<iomanip>
# include<vector>
# include<stack>
# include<queue>
# include<map>
# include<unordered_map>
# include<unordered_set>

# define mod 10000000007
using namespace std;

struct trie {
    trie *nxt[26];
    bool ended;

    trie() {
        for (int i = 0; i < 26; i++) {
            nxt[i] = NULL;
        }
        ended = false;
    }
};

trie *root;

void insert(string s) {
    trie *current = root;
    for (int i = 0; i < s.size(); i++) {
        if (current->nxt[s[i] - 'a'] == NULL) {
            current->nxt[s[i] - 'a'] = new trie();
        }
        current = current->nxt[s[i] - 'a'];
    }
    current->ended = true;
}

bool in_trie(string s) {
    trie *current = root;
    for (int i = 0; i < s.size(); i++) {
        if (current->nxt[s[i] - 'a'] == NULL) {
            return false;
        }
        current = current->nxt[s[i] - 'a'];
    }
    return current->ended;
}

int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    */
    root = new trie();
    insert("apar");
    insert("aryan");
    insert("shivam");

    if (in_trie("aapar")) {
        cout << "Yes found";
    } else {
        cout << "Not found";
    }
    return 0;
}

