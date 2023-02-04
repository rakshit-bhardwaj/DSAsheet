#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    map<int,int> vis;
    stack<int> s;

    void dfs(int x,vector<int> adj[]){
        vis[x] = 1;
        for(int i =0;i<adj[x].size();i++) if(!vis[adj[x][i]]) dfs(adj[x][i],adj);
        s.push(x);
    }
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
        for(int i =0;i<V;i++) if(!vis[i]) dfs(i,adj);
        
        while(!s.empty()){
            int f = s.top();
            s.pop();
            ans.push_back(f);
        }
        return ans;
	}
};