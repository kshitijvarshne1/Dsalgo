/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 20-Nov-20
*   Time: 10:47 PM
*   File: CycleDetectionInAUndirectedGraphUsingDSU.cpp
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
        return findSet(parent[i], parent);
    }

    //union
    int unionSet(int x, int y, int parent[]) {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        if (s1 != s2) {
            parent[s1] = s2;
        }
    }

    bool containsCycle() {
        //DSU logic to check if graph contains cycle or not
        int *parent = new int[v];
        for (int i = 0; i < v; i++) {
            parent[i] = -1;
        }
        //iterate overe the edge list
        for (auto edge : l) {
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if (s1 != s2) {
                unionSet(s1, s2, parent);
            } else {
                return true;
            }

        }
        //delete[]parent;
        return false;
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    if (g.containsCycle()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}

