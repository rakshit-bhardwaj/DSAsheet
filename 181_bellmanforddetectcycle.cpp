#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int n;
const int inf = 1000000;
bool bellmanford(){
    vector<int> dist(n,inf);
    dist[0] = 0;
    int k = n -1;
    while(k--){
        for(auto x : graph){
            if(dist[x[0]] + x[2] < dist[x[1]]){
                dist[x[1]] = dist[x[0]] + x[2];
            }
        }
    }

    for(auto x : graph){
            if(dist[x[0]] + x[2] < dist[x[1]]){
                return true;
            }
        }
    return false;
}

int main () {
    graph = {{0,1,-1},
             {0,2,4},
             {1,2,3},
             {1,3,2},
             {1,4,2},
             {3,2,5},
             {3,1,1},
             {4,3,-1}};
    n = 6;

    if(bellmanford()) cout<<"yes";
    else cout<<"no";
    return 0;
}
