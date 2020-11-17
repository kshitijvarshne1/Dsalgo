/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 17-Nov-20
*   Time: 2:38 PM
*   File: AdjacentImplementationFromGenericData.cpp
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
    //Adjacency list
    unordered_map<string, list<pair<string, int>>> l;   //Hashing
public:
    void addEdge(string x, string y, bool bidir, int wt) {
        l[x].push_back(make_pair(y, wt));
        if (bidir) {
            l[y].push_back(make_pair(x, wt));
        }
    }

    void printAdjacencyList() {
        //Iterate over all the keys in the map
        for (auto p:l) {
            string city = p.first;
            list<pair<string, int>> nbrs = p.second;
            cout << city << " -> ";
            for (auto nbr : nbrs) {
                string destination = nbr.first;
                int distance = nbr.second;
                cout << destination << " " << distance << " , ";
            }
            cout << endl;
        }
    }
};
int main() {
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);
    g.printAdjacencyList();

    return 0;
}

