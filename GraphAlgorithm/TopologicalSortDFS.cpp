/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 18-Nov-20
*   Time: 12:07 AM
*   File: TopologicalSortDFS.cpp
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
    void addEdge(T x, T y) {
        l[x].push_back(y);
    }

    void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering) {
        //Recursive function that will transverse graph
        visited[src] = true;
        //go to the all nbr of that node is not visited
        for (T nbr:l[src]) {
            if (!visited[nbr]) {
                dfs_helper(nbr, visited, ordering);
            }
        }
        ordering.push_front(src);
        return;
    }

    void dfs() {
        map<T, bool> visited;
        list<T> ordering;
        //mark all the nodes as not visited in the beginning
        for (auto p:l) {
            T node = p.first;
            visited[node] = false;
        }
        //iterate over all the vertices and call a dfs call
        for (auto p:l) {
            T node = p.first;
            if (!visited[node]) {
                dfs_helper(node, visited, ordering);
            }
        }
        //finally print the list
        for (auto node:ordering) {
            cout << node << endl;
        }
    }
};

int main() {
    Graph<string> g;
    g.addEdge("Pyhton", "Data Preprocessing");
    g.addEdge("Pyhton", "Pytorch");
    g.addEdge("Pyhton", "ML");
    g.addEdge("Data Preprocessing", "ML");
    g.addEdge("Pytorch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "Face Recogn");
    g.addEdge("Data Set", "Face Recogn");
    g.dfs();

    return 0;
}


