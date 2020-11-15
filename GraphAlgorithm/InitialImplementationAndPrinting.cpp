/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 16-Nov-20
*   Time: 12:02 AM
*   File: InitialImplementationAndPrinting.cpp
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
    int v;
    //Array of list
    list<int> *l;
public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int x, int y) {
        //assuming edges are Bidirectional
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printAdjacencyList() {
        //Iterate over all the vertices
        for (int i = 0; i < v; i++) {
            cout << "vertex " << i << "->";
            for (int nbr:l[i]) {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.printAdjacencyList();

    return 0;
}