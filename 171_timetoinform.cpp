#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = INT_MIN;
    int N,hid;
    vector<int> man,inf;
    unordered_map <int,vector<int>> tree;

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 1) return 0;
        // man = manager; 
        inf = informTime;
        // N = n;
        for(int i = 0;i<n;i++){
            if(manager[i]!=-1){
                tree[manager[i]].push_back(i);
            }
        }
        solve(headID);
        return ans;
    }

    void solve(int x,int t=0){
        cout<<"cur = "<<x<<endl;
        for(int i =0;i<tree[x].size();i++){
            solve(tree[x][i],t + inf[x]);
        }
        ans = max(ans,t);
    }
};