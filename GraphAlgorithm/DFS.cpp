/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 17-Nov-20
*   Time: 3:20 PM
*   File: DFS.cpp
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

    void dfs(T src) {
        map<T, bool> visited;
        //mark all the nodes as not visited in the beginning
        for (auto p:l) {
            T node = p.first;
            visited[node] = false;
        }
        //call the helper function
        dfs_helper(src, visited);
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.dfs(0);
    return 0;
}

