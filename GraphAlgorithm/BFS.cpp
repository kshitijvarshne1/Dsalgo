/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 17-Nov-20
*   Time: 3:16 PM
*   File: BFS.cpp
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
        l[y].push_back(x);
    }

    void bfs(T src) {
        map<T, bool> visited;
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for (int nbr : l[node]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    //mark that nbs as visited
                    visited[nbr] = true;
                }
            }
        }
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
    g.bfs(0);

    return 0;
}

