#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> graph;
        int ans = INT_MAX;
        
        graph.resize(n,vector<int> (n,-1));
        for(int i=0;i<flights.size();i++) graph[flights[i][0]][flights[i][1]] = flights[i][2];
        vector<int> mincost (n,INT_MAX);
        queue<pair<int,int>> q;
        int count = 0;
        q.push({src,0});
        while(!q.empty() && count<=k){
            int size = q.size();
            while(size--){
                auto cur = q.front();
                q.pop();
                for(int i =0;i<graph[cur.first].size();i++){
                    if(graph[cur.first][i]!=-1 && graph[cur.first][i] + cur.second < mincost[i]){
                        mincost[i] = graph[cur.first][i] + cur.second;
                        q.push({i,graph[cur.first][i] + cur.second});
                    }
                } 
            }
            count++;
        }
        if(mincost[dst] ==INT_MAX) return -1;
        return mincost[dst];
    }
};