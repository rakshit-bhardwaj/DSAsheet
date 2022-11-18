#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int cyclestart = -1;
    unordered_set<int> cyclenodes;


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> graph(edges.size()+1);
        map<int,int> visited;
        for(auto i: edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        cout<<"dfs -> ";
        dfs(graph,visited,1);
        cout<<"\n";

        cout<<"nodes in the cycle => ";
        for(auto i: cyclenodes){
            cout<<i<<" ";
        }
        cout<<endl;
        
        for(int i =edges.size()-1;i>=0;i--){
            cout<<"current edge => {"<<edges[i][0]<<","<<edges[i][1]<<"}"<<endl;
            if(cyclenodes.count(edges[i][0]) && cyclenodes.count(edges[i][1])) return edges[i]; 
        }
        return {};
    }

    void dfs(vector<vector<int>> &graph,map<int,int> &visited,int cur,int par = -1){
        if(visited[cur]==1) {
            cyclestart = cur;
            cout<<"cycle started at "<<cur<<endl;
            return;
        }
        cout<<cur<<" ";
        visited[cur] = 1;
        for(auto child: graph[cur]){
            if(child == par) continue;
            if(cyclenodes.empty()) dfs(graph,visited,child,cur);
            if(cyclestart != -1) cyclenodes.insert(cur);
            if(cur == cyclestart){
                cyclestart = -1;
                return;
            }
        } 
    }
};