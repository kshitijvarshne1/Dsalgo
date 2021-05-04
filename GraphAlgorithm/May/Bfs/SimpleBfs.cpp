/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 04-May-21
*   Time: 3:07 PM
*   File: SimpleBfs.cpp
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

# define modValue 1e9 + 7
# define ll long long int
# define cin ios_base::sync_with_stdio(false);cin.tie(NULL); cin
using namespace std;

void printGraph(std::vector<int> adj[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << i << " -> ";
        for (int x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}

void bfs(std::vector<int> adj[], int n, int source) {
    vector<int> v(n, 0);
    queue<int> q;
    q.push(source);
    v[source] = 1;
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        cout << temp << " ";
        for (int x : adj[temp]) {
            if (v[x] == 0) {
                q.push(x);
                v[x] = 1;
            }
        }
    }
    cout << endl;
}


//Undirected graph
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    printGraph(adj, n);
    bfs(adj, n, 3);
    return 0;
}

