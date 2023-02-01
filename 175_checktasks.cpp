#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
unordered_map<int,int> vis;
bool cycle= false;

void dfs(int x){
    if(vis[x]) {
        cycle = true;
        return;
    }
    vis[x] = 1;
    for(auto i : edges[x]){
        dfs(i);
    }
}

bool solve(int n,vector<vector<int>> dep){
    edges.resize(n+1);
    for(auto x: dep) edges[x[1]].push_back(x[0]);
    for(int i =0;i<n;i++){
        vis.clear();
        dfs(i);
        if(cycle) return false;
    }
    return true;
}



int main () {
    vector<vector<int>> dep = {{1, 0}, {0, 1}};
    cout<<solve(2,dep);
    return 0;
}