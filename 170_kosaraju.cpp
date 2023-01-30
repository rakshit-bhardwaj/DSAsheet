#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    stack<int> s;
    map<int,int> vis;

    void dfs(int x,vector<int> adj[]){
        vis[x] = 1;
        for(auto y : adj[x]){
            if(!vis[y]) dfs(y,adj);
        }
        s.push(x);
    }
	
    int kosaraju(int V, vector<int> adj[])
    {
       vector<int> trans[V];
       int ans = 0;
        for(int i =0;i<V;i++){
            if(!vis[i]) dfs(i,adj);
        }

        for(int i =0;i<V;i++){
            vis[i] = 0;
            for(auto j : adj[i]){
                trans[j].push_back(i);
            }
        }

        while(!s.empty()){
            int x = s.top();
            s.pop();
            if(!vis[x]){
                ans++;
                dfs(x,trans);
            }
        }
        return ans;
    }
};