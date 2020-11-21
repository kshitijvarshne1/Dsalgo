/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 21-Nov-20
*   Time: 4:17 PM
*   File: BipartiteGraph.cpp
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

bool dfs_helper(vector<int> graph[], int node, int *visited, int parent, int color) {
    //come to node
    visited[node] = color; //1 or 2, both mean visited

    for (auto nbr : graph[node]) {

        if (visited[nbr] == 0) {
            int subprob = dfs_helper(graph, nbr, visited, node, 3 - color);

            if (subprob == false) {
                return false;
            }

        } else if (nbr != parent and color == visited[nbr]) {
            return false;
        }

    }
    return true;
}


bool dfs(vector<int> graph[], int n) {

    int visited[1000] = {0};  // 0- Not Visited, 1 - Visited Color is 1, 2 - Visted Color 2

    int color = 1;
    int ans = dfs_helper(graph, 0, visited, -1, color);
    //later one

    //colors
    for (int i = 0; i < n; i++) {
        cout << i << " - Color " << visited[i] << endl;
    }

    //
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> graph[n];
    while (m--) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    //BFS or DFS by coloring the nodes at each step (current node has color 1 , nbr should have a color 2)

    if (dfs(graph, n)) {
        cout << "Yes it is bipartite";
    } else {
        cout << "Not Bipartite";
    }
    return 0;
}

