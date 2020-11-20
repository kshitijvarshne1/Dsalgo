/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 20-Nov-20
*   Time: 10:56 PM
*   File: UndirectedGraphIsATreeOrNotUsingDFS.cpp
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

    bool cycle_helper(int node, bool *visited, int parent) {
        visited[node] = true;
        for (auto nbr: l[node]) {
            //two cases
            if (!visited[nbr]) {
                //go recursively visit the node
                bool cycle_mila = cycle_helper(nbr, visited, node);
                if (cycle_mila) {
                    return true;
                }
            }
                //nbr is visited but nbr should not be equal to parent
            else if (nbr != parent) {
                return true;
            }
        }
        return false;
    }

    bool contains_cycle() {
        //check for cycle in undirected graph
        bool *visited = new bool[v];
        for (int i = 0; i < v; i++) {
            visited[i] = false;
        }
        return cycle_helper(0, visited, -1);
    }

};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    if (g.contains_cycle()) {
        cout << "yes";
    } else {
        cout << "No";
    }
    return 0;
}

