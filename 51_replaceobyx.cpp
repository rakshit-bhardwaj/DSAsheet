#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

bool check(int x,int y,vector<vector<char>> &board,pair<int,int> d){
    if(x + d.first >= board.size() || x + d.first < 0 || y + d.second >=board[0].size() || y + d.second < 0)
        return false;
    return true;
}

void dfs(vector<vector<char>> &board,int i,int j){
    for(int k=0;k<dir.size();k++){
        if(check(i,j,board,dir[k])){
            if(board[i + dir[k].first][j + dir[k].second] == '-'){
                board[i + dir[k].first][j + dir[k].second] = 'O';
                dfs(board,i+dir[k].first,j+dir[k].second);
            }      
        }
    }
}

void xbyo(vector<vector<char>> &board){
    bool ocheck;
    for(int i = 1;i<board.size()-1;i++){
        for(int j = 1;j<board[0].size()-1;j++){
            if(board[i][j]=='O') board[i][j] = '-';
        }
    }
    cout<<"after updating with '-' => "<<endl;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"--------------------------"<<endl;
    int i=0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(i==0 || j ==0 || i == board.size() - 1|| j == board[0].size() -1){
                if(board[i][j]=='O'){
                    dfs(board,i,j);
                }
            }
        }
    }

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='-') board[i][j] = 'X';
        }
    }
    
}

int main () {
    vector<vector<char>> board = 
    {{'X', 'O', 'X', 'X', 'X', 'X'},
    {'X', 'O', 'X', 'X', 'O', 'X'},
    {'X', 'X', 'X', 'X', 'X', 'X'},
    {'O', 'X', 'O', 'X', 'X', 'X'},
    {'X', 'X', 'X', 'O', 'X', 'O'},
    {'O', 'O', 'X', 'O', 'O', 'O'}};
    vector<vector<char>> ans = 
    {{'X', 'O', 'X', 'X', 'X', 'X'},
    {'X', 'O', 'X', 'X', 'X', 'X'},
    {'X', 'X', 'X', 'X', 'X', 'X'},
    {'O', 'X', 'X', 'X', 'X', 'X'},
    {'X', 'X', 'X', 'O', 'X', 'O'},
    {'O', 'O', 'X', 'O', 'O', 'O'}};
    xbyo(board);
    bool anscheck= true;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[i][j]<<" ";
            if(board[i][j]!=ans[i][j]) anscheck=false;
        }
        cout<<endl;
    }
    if(anscheck) cout<<"correct";
    else cout<<"incorrect";

    return  0;
}
