#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int,int> visited;
    vector<vector<int>> edges;

    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n - 1) return -1;
        edges.resize(n);
        for(auto x: connections){
            edges[x[0]].push_back(x[1]);
            edges[x[1]].push_back(x[0]);
        }
        int c = 0;
        for(int i =0;i<n;i++){
            if(!visited[i]){
                c++;
                dfs(i);
            }
        }
        return c-1;
    }

    void dfs(int x){
        if(visited[x]) return;
        visited[x] = 1;
        for(auto y : edges[x]) dfs(y);
    }
};