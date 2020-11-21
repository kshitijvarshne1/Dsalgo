/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 20-Nov-20
*   Time: 10:52 PM
*   File: DijkstraAlgoSSSPA.cpp
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
    unordered_map<T, list<pair<T, int>>> m;
public:
    void addEdge(int x, int y, int distance, bool bidir = true) {
        m[x].push_back(make_pair(y, distance));
        if (bidir) {
            m[y].push_back(make_pair(x, distance));
        }
    }

    void printAdj() {
        //Let try to print the adj list
        //Iterate over all the key value pair in the map
        for (auto j: m) {
            cout << j.first << "->";
            for (auto l : j.second) {
                cout << "( " << l.first << " , " << l.second << " )";
            }
            cout << endl;
        }
    }

    void dijsktraSSSPA(T src) {
        unordered_map<T, int> distance;
        //set all distance to infinity
        for (auto j: m) {
            distance[j.first] = INT_MAX;
        }
        //make a set to find out node with the minimul difference
        set<pair<int, T>> s;
        distance[src] = 0;
        s.insert(make_pair(0, src));
        while (!s.empty()) {
            //find the pair at the front
            auto p = s.begin();
            T node = p->second;
            int nodeDistance = p->first;
            s.erase(s.begin());

            //Iterate over nbr of current node

            for (auto childpair : m[node]) {
                if (nodeDistance + childpair.second < distance[childpair.first]) {
                    //In the set , updation of a particular is not possible
                    //We have to remove the old pair and insert the new pair to simulation updation
                    T destination = childpair.first;
                    auto F = s.find(make_pair(distance[destination], destination));

                    if (F != s.end()) {
                        s.erase(F);
                    }
                    //Insert new pair
                    distance[destination] = nodeDistance + childpair.second;
                    s.insert(make_pair(distance[destination], destination));
                }
            }
        }
        //Lets print distance to all other node from src
        for (auto d:distance) {
            if (d.first != src) {
                if (d.second != INT_MAX) {
                    cout << d.first << " is loacetd at a distance of " << d.second << endl;
                } else {
                    cout << d.first << " is loacetd at a distance of " << " -1 " << endl;
                }
            }
        }
    }
};

int main() {
    Graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 7);
    g.dijsktraSSSPA(1);
    return 0;
}
