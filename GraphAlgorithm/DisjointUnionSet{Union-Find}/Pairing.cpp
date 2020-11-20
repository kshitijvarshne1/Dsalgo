/*
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 20-Nov-20
*   Time: 10:50 PM
*   File: Pairing.cpp
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

class Graph {
    int v;
    list<pair<int, int>> l;
public:
    Graph(int v) {
        this->v = v;
    }

    void addEdge(int x, int y) {
        l.push_back(make_pair(x, y));
    }

    //Find
    int findSet(int i, int parent[]) {
        //base case
        if (parent[i] == -1) {
            return i;
        }
        return parent[i] = findSet(parent[i], parent);
    }

    //union
    void unionSet(int x, int y, int parent[], int rank[]) {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

    int pairing() {
        //DSU Logic
        int *parent = new int[v];
        int *rank = new int[v];
        for (int i = 0; i < v; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
        //code logic
        int ans = 0;
        for (auto edge : l) {
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            unionSet(s1, s2, parent, rank);
        }
        for (int i = 0; i < v; i++) {
            ans += v - rank[findSet(i, parent)];
        }
        delete[] parent;
        delete[]rank;
        return ans / 2;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }
    cout << g.pairing();
    return 0;
}


