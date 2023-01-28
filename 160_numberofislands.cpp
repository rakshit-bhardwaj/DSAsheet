#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> gr;
    int r,c;
    map<pair<int,int>,bool> visited;
    int ans=0;

    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();c = grid[0].size();
        gr = grid;
        for(int i=0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(grid[i][j]=='1'){
                    if(bfs(i,j)) ans++;
                }
            }
        }
        return ans;
    }
    
    int bfs(int x,int y){
        if(x<0 || y<0) return 0;
        if(x>=r || y>=c) return 0;
        if(visited[{x,y}]) return 0;
        if(gr[x][y]=='0') return 0;
        else {
            visited[{x,y}] = true;
            bfs(x+1,y);
            bfs(x,y+1);
            bfs(x-1,y);
            bfs(x,y-1);
        }
        return 1;
    }
};
