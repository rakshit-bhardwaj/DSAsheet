#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> i;
    map<pair<int,int>,bool> visited;
    int r,c,scol,col;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        r = image.size();
        c = image[0].size();
        i = image;
        scol = image[sr][sc];
        col = color;
        bfs(sr,sc);
        return i;
    }

    void bfs(int x,int y){
        if(x < 0 || y < 0) return;
        if(x >= r || y >= c) return;
        if(visited[{x,y}]) return;
        visited[{x,y}] = true;
        if(i[x][y] == scol){
            i[x][y] = col;
            bfs(x+1,y);
            bfs(x,y+1);
            bfs(x-1,y);
            bfs(x,y-1);
        }
    }
};
