#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void state(vector<vector<int>>& board,vector<vector<int>> &updatedboard,int i,int j){
        //cout<<board[i][j]<<" ";
        //cout<<"flag ["<<i<<"]["<<j<<"] "<<endl;
        int livecount = 0;
        
        if(i>0 && j>0){
            if(board[i-1][j-1] == 1) livecount ++;
        }
         
        if(i<board.size()-1 && j<board[0].size()-1){
            if(board[i+1][j+1] == 1) livecount ++;
        }
       
        if(i<board.size()-1 && j>0){
            if(board[i+1][j-1] == 1) livecount ++;
        }
        
        if(i>0 && j<board[0].size()-1){
            if(board[i-1][j+1] == 1) livecount ++;
        }
        
        if(i>0){
            if(board[i-1][j]==1) livecount ++;
        }
        if(i<board.size()-1){
            if(board[i+1][j]==1) livecount ++;
        }
        if(j>0){
            if(board[i][j-1]==1) livecount ++;
        }
        if(j<board[0].size()-1){
            if(board[i][j+1]==1) livecount ++;
        }
        
        if(board[i][j]==1){
            if (livecount<2 || livecount > 3) updatedboard[i][j]=0;
        }
        if(board[i][j]==0){
            if (livecount==3) updatedboard[i][j]=1;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> updatedboard=board;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                state(board,updatedboard,i,j);
            }
        }
        board = updatedboard;
    }
};


int main (){
    Solution obj;

    vector<vector<int>> board = {{1,1},{1,0}};
    obj.gameOfLife(board);
    for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
}