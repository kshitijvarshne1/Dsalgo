/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 21-Nov-20
*   Time: 11:17 AM
*   File: FloydWarshallAlgo.cpp
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
# define INF 1000
using namespace std;

vector<vector<int>> floydWarshall(vector<vector<int>> graph) {
    vector<vector<int>> distance(graph);
    int v = graph.size();
    //phase , in kth phase we included vertices (1,2...k) as intermediate vertices
    for (int k = 0; k < v; k++) {
        //Iterate over the entire 2D vertices matrix
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                //vertex k is included and we can minimise the distance
                if (distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
    return distance;
}

int main() {
    //4 vertices (4*4) matix
    vector<vector<int>> graph = {
            {0,   INF, -2, INF},
            {4,   0,   3,  INF},
            {INF, INF, 0,  2},
            {INF, -1, INF, 0}
    };
    auto result = floydWarshall(graph);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result.size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

