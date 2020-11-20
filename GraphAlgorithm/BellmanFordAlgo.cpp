/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 21-Nov-20
*   Time: 12:13 AM
*   File: BellmanFordAlgo.cpp
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

vector<int> bellmanFordAlgo(int v, int src, vector<vector<int>> edges) {
    //create a vector
    vector<int> distance(v + 1, INT_MAX);
    distance[src] = 0;

    for (int i = 0; i < v - 1; i++) {
        for (auto edge:edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (distance[u] != INT_MAX and distance[u] + wt < distance[v]) {
                distance[v] = distance[u] + wt;
            }
        }
    }
    //negative weight cycle
    for (auto edge:edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if (distance[u] != INT_MAX and distance[u] + wt < distance[v]) {
            cout << "negative cycle found ";
            exit(0);
        }
    }
    return distance;
}

int main() {
    int v, e;
    cin >> v >> e;
    //edge list
    vector<vector<int>> edges;

    for (int i = 0; i < e; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }
    vector<int> distance = bellmanFordAlgo(v, 1, edges);
    for (int i = 1; i <= v; i++) {
        cout << "Node " << i << " is at a distance " << distance[i] << endl;
    }
    return 0;
}
