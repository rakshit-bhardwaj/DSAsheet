#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> ans;
    int gn;
    vector<vector<int>> grid;
    vector<string> findPath(vector<vector<int>> &m, int n) {
       gn = n;string curpath;
       map<pair<int,int>,int> visited;
       grid = m;
       dfs(0,0,visited,curpath);
       return ans;
    }

    void dfs(int x,int y,map<pair<int,int>,int> visited,string curpath){
        if(x < 0 || y < 0) return;
        if(x >= gn || y >= gn) return;
        if(visited[{x,y}]) return;
        if(grid[x][y]==0) return;
        if(x == gn-1 && y == gn-1) {ans.push_back(curpath); return;}
        visited[{x,y}] = 1;
        curpath.push_back('D');
        dfs(x+1,y,visited,curpath);
        curpath.pop_back();
        curpath.push_back('R');
        dfs(x,y+1,visited,curpath);
        curpath.pop_back();
        curpath.push_back('U');
        dfs(x-1,y,visited,curpath);
        curpath.pop_back();
        curpath.push_back('L');
        dfs(x,y-1,visited,curpath);
        curpath.pop_back();
        visited[{x,y}] = 0;
        return;
    }
};

int main(){
    int n = 4;
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    Solution obj;
    vector<string> ans = obj.findPath(m,n);
   
    return 0;
}