/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 20-Nov-20
*   Time: 10:54 PM
*   File: KruksalAlgo-MinimumSpanningtree.cpp
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

class DSU {
    int *parent;
    int *rank;
public:
    DSU(int v) {
        parent = new int[v];
        rank = new int[v];

        //parent=-1 rank=1;
        for (int i = 0; i < v; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    //Find Function
    int find(int i) {
        //base case
        if (parent[i] == -1) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    //Unite->Union Function

    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            //union by rank
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph {
    vector<vector<int>> edgelist;
    int v;
public:
    Graph(int v) {
        this->v = v;
    }

    void addEdge(int x, int y, int w) {
        edgelist.push_back({w, x, y});
    }
    //Initialise a DSU

    int kruksal_mst() {
        //1. Sort all the edges based upon weight
        sort(edgelist.begin(), edgelist.end());
        DSU s(v);
        int ans = 0;
        for (auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            //take that edge in MST if it doesn'tform a cycle
            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 3, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);
    cout << g.kruksal_mst();

    return 0;
}

