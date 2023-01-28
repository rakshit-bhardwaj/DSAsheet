#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    map<int,bool> vis;
    bool ans=false;
    static int v;
    bool isCycle(int V, vector<int> adj[]) {
        v = V;
        for(int i =0;i<V;i++){
            if(!vis[i])
            dfs(i,-1,adj);
            if(ans) return true;
        }
        return false;
    }

    void dfs(int cur,int par,vector<int> (adj) []){
        if(ans) return;
        vis[cur] = 1;
        for(auto x : adj[cur]){
            if(!vis[x])
            dfs(x,cur,adj);
            else {
                if(x!=par) ans = true;
                return;
            }
        }
    }
};