/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 17-Nov-20
*   Time: 3:45 PM
*   File: ConnectedComponentsOfGraphs.cpp
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

template<typename T>
class Graph {
    map<T, list<T>> l;
public:
    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src, map<T, bool> &visited) {
        //Recursive function that will transverse graph
        cout << src << " ";
        visited[src] = true;
        //go to the all nbr of that node is not visited
        for (T nbr:l[src]) {
            if (!visited[nbr]) {
                dfs_helper(nbr, visited);
            }
        }
        return;
    }

    void dfs() {
        map<T, bool> visited;
        //mark all the nodes as not visited in the beginning
        for (auto p:l) {
            T node = p.first;
            visited[node] = false;
        }
        //iterate over all the vertices and call a dfs call
        int cnt = 0;
        for (auto p:l) {
            T node = p.first;
            if (!visited[node]) {
                cout << "component" << cnt << "->";
                dfs_helper(node, visited);
                cnt++;
                cout << endl;
            }
        }
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(0, 4);

    g.addEdge(5, 6);
    g.addEdge(6, 7);

    g.addEdge(8, 8);
    g.dfs();

    return 0;
}