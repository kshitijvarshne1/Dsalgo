/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 17-Nov-20
*   Time: 3:17 PM
*   File: SSSPA.cpp
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

    void SSSPA(T src) {
        map<T, int> dist;
        queue<T> q;
        //All other node will have INT_MAX
        for (auto node_pair:l) {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;

        while (!q.empty()) {
            T node = q.front();
            q.pop();

            for (int nbr : l[node]) {
                if (dist[nbr] == INT_MAX) {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }
        //print the dist to every node
        for (auto node_pair:l) {
            T node = node_pair.first;
            int d = dist[node];
            cout << "Node " << node << " Dist from src " << d << endl;
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
    g.SSSPA(0);

    return 0;
}


