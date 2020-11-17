/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 17-Nov-20
*   Time: 8:28 PM
*   File: SnakeAndLadderWithInput.cpp
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
        //l[y].push_back(x); comment->due to inputs are only directional
    }

    int bfs(T src, T destination) {
        map<T, int> dist;
        queue<T> q;
        map<T, T> parent;
        //All other node will have INT_MAX
        for (auto node_pair:l) {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while (!q.empty()) {
            T node = q.front();
            q.pop();

            for (int nbr : l[node]) {
                if (dist[nbr] == INT_MAX) {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                    parent[nbr] = node;
                }
            }
        }
        //Dest to src
        T temp = destination;
        while (temp != src) {
            // cout << temp << "<-";
            temp = parent[temp];
        }
        //cout << src << endl;
        //return and print the distance to destination node
        return dist[destination];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, s;
        cin >> n >> l >> s;
        int board[1000] = {0};

        for (int i = 0; i < l; i++) {
            int x, y;
            cin >> x >> y;
            board[x] = y - x;
        }
        for (int i = 0; i < s; i++) {
            int x, y;
            cin >> x >> y;
            board[x] = x - y;
        }
//        board[2] = 13;
//        board[5] = 2;
//        board[9] = 18;
//        board[18] = 11;
//        board[17] = -13;
//        board[20] = -14;
//        board[24] = -8;
//        board[25] = 10;
//        board[32] = -2;
//        board[34] = -22;

        //Add edge to the graph
        Graph<int> g;
        for (int i = 0; i <= n; i++) {
            for (int dice = 1; dice <= 6; dice++) {
                int j = i + dice;
                j += board[j];
                if (j <= n) {
                    g.addEdge(i, j);
                }
            }
        }
        g.addEdge(n, n);
        cout << g.bfs(0, n);
    }
    return 0;
}
/*
Input:-
1
30 4 4
3 22
5 8
11 26
20 29
17 4
19 7
21 9
27 1

Output:-
3
*/
