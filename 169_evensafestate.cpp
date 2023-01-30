#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> ans;
    vector<bool> safe;
    map<int,int> stored;
    vector<vector<int>> gr;
    

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        gr = graph;
        safe.resize(graph.size());
        for(int i =0;i<graph.size();i++){
            if(dfs(i)) ans.push_back(i);
        }
        return ans;
    }

    bool dfs(int x){
        if(stored[x]) return safe[x];
        safe[x] = false;
        stored[x] = 1;
        for(int i =0;i<gr[x].size();i++){
            if(!dfs(gr[x][i])) return false;
        } 
        safe[x] = true;
        return true;
    }
};