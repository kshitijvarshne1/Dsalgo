/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 19-Nov-20
*   Time: 12:12 AM
*   File: DirectedGraphIsTreeOrNotUsingDFS.cpp
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
        //directed edge
        l[x].push_back(y);
    }

    void topologicalSort() {
        //indegree
        int *indegree = new int[v];
        for (int i = 0; i < v; i++) {
            indegree[i] = 0;
        }
        //update indedgree by traversing edges x->y indegree[y]++
        for (int i = 0; i < v; i++) {
            for (auto y:l[i]) {
                indegree[y]++;
            }
        }
        //bfs
        //1. step -> Find the nodes with a indegree
        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        //start removing elements from the queue
        while (!q.empty()) {
            int node = q.front();
            cout << node << " ";
            q.pop();

            //iterate over nbr of that node and reduce their indegree by 1
            for (auto nbr:l[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(2, 5);

    g.topologicalSort();
    return 0;
}

