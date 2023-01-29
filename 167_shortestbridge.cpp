#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<pair<int,int>,int> vis;
    vector<pair<int,int>> ivec;
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    int n;
    int shortestBridge(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        n = grid.size();
        bool check = false;
        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1) {
                    markis(i,j,grid);
                    check = true;
                    break;
                }
            }
            if(check) break;
        }
        ans = bfs(grid);
        return ans;
    }

    void markis(int x,int y,vector<vector<int>>& grid){
        if(x < 0 || y < 0 || x >= n || y >= n || vis[{x,y}] || !grid[x][y]) return;
        vis[{x,y}] = 1;
        ivec.push_back({x,y});
        for(int i =0;i<4;i++){
            markis(x + dx[i],y + dy[i],grid);
        }
    }

    int bfs(vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        int ans = 0;
        for(auto x: ivec) q.push({x.first,x.second});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto cur = q.front();
                q.pop();
                for(int i =0;i<4;i++){
                    int xx = cur.first + dx[i];
                    int yy = cur.second + dy[i];
                    if(xx < 0 || yy < 0 || xx >= n || yy >= n || vis[{xx,yy}]) continue;
                    if(grid[xx][yy]==1) return ans;
                    q.push({xx,yy});
                    vis[{xx,yy}]=1;
                }
            }  ans++;
        }
        return ans;
    }
};
