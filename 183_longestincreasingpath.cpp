#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,-1,1};
    int m,n;
    vector<vector<int>> memo;

    bool checkp(int x,int y){
        if(x <0 || y<0 || x >= m || y >= n) return false;
        return true;
    }

    int dfs(int x, int y,vector<vector<int>>& matrix){
        if(memo[x][y]) return memo[x][y];
        memo[x][y] = 1;
        for(int i =0;i<4;i++){
            if(checkp(x+dx[i],y+ dy[i]) && matrix[x][y]<matrix[x+dx[i]][y+dy[i]]){
                memo[x][y] = max(memo[x][y],dfs(x+dx[i],y +dy[i],matrix) + 1);
            }
        }
        return memo[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        m = matrix.size();
        n = matrix[0].size();
        memo.resize(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans,dfs(i,j,matrix));
            }
        }
        return ans;
    }
};