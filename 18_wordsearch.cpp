#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<pair<int,int>> vis;
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();
        bool check = false;
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(board[i][j]==word[0])
                check = dfs(i,j,0,board,word);
                if(check) return true;
            }
        }
        return false;
    }


    bool dfs(int r,int c,int i,vector<vector<char>>& board, string word){
        int ROWS = board.size();
        int COLS = board[0].size();
        if(i==word.size()) return true;
        if(r<0 || c<0 || r == ROWS || c == COLS|| board[r][c]!=word[i]) return false;
        char seno = board[r][c];
        board[r][c]='1';
        bool check = dfs(r+1,c,i+1,board,word) || dfs(r-1,c,i+1,board,word) || dfs(r,c+1,i+1,board,word) || dfs(r,c-1,i+1,board,word);
        board[r][c]=seno;
        return check;
    }
};