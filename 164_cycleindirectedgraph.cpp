#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    map<int,bool> vis;
    bool ans=false;
    
    bool isCycle(int V, vector<int> adj[]) {

        for(int i =0;i<V;i++){
            vis.clear();
            dfs(i,adj);
            if(ans) return true;
        }
        return false;
    }

    void dfs(int cur,vector<int> adj[]){
        if(ans) return;
        if(vis[cur]==1){ans = true; return;}
        vis[cur] = 1;
        for(auto x : adj[cur]){
            dfs(x,adj);
        }
    }
};

int main () {
    Solution o;
    vector<int> adj[] = {{0,1},{0,2},{1,2},{2,0},{2,3},{3,3}};
    int v = 4;
    cout<<o.isCycle(v,adj);
    return 0;
}

