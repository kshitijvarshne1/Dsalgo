/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 19-Nov-20
*   Time: 12:14 AM
*   File: UndirectedGraphIsATreeOrNot.cpp
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
    list<int> *l;
    int v;
public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool isTree() {
        bool *visited = new bool[v];
        int *parent = new int[v];
        queue<int> q;
        for (int i = 0; i < v; i++) {
            visited[i] = false;
            parent[i] = i;
        }
        int src = 0;
        q.push(src);
        visited[src] = true;
        //pop out one node and visit its nbs
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nbr : l[node]) {
                if (visited[nbr] = true and parent[node] != nbr) {
                    return false;
                } else if (!visited[nbr]) {
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }

            }
        }
        return true;
    }


};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    if (g.isTree()) {
        cout << "yes";
    } else {
        cout << "No";
    }
    return 0;
}

