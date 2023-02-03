#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int,pair<int,int>> m;

    void converttocord(int n){
        int num = 1;
        int c = 1;
        for(int i =n-1;i>=0;i--){
            if(c%2!=0){
                for(int j = 0;j<n;j++){
                    m[num] = {i,j};
                    num++;
                }
            }
            else {
                for(int j = n-1;j>=0;j--){
                    m[num] = {i,j};
                    num++;
                }
            }
            c++;
        }
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        converttocord(n);
        queue<int> q;
        q.push(1);
        map<int,int> vis;
        vis[1] = 1;
        int ans = INT_MAX;
        int count =0;
        while(!q.empty()){
            int size = q.size();
            for(int k =0;k<size;k++){
                int cur = q.front();
                q.pop(); 
                cout<<"current -> "<<cur<<" count -> "<<count<<endl;
                if(cur==n*n) ans = min(count,ans);
                pair<int,int> cord = m[cur];
                if(board[cord.first][cord.second]!=-1){
                    cout<<cur<<" = "<<board[cord.first][cord.second]<<endl;
                    cur = board[cord.first][cord.second];
                    if(cur==n*n) ans = min(count,ans);
                    if(vis[cur]) continue;
                    cout<<"current -> "<<cur<<" count -> "<<count<<endl;
                } 
            
                for(int i=cur+1;i<=min(cur + 6,n*n);i++){
                    if(!vis[i]){
                        vis[i] = 1;
                        q.push(i);
                    }
                }
            }
            count ++;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};



-1,  1,  2, -1
 2, 13, 15, -1
-1, 10, -1, -1
-1,  6,  2,  8

16 15 14 13 
 9 10 11 12
 8  7  6  5 
 1  2  3  4
