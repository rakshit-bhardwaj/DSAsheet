#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> o,z;
    int n,ans=0;

    int calcd(int x1,int y1,int x2, int y2){
        return (abs(x1 - x2) + abs(y1 - y2));
    }

    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) o.push_back({i,j});
                else z.push_back({i,j});
            }
        }

        if(!o.size() || !z.size()) return -1;
        for(auto zc : z){
            int curm = INT_MAX;
            for(auto oc : o){
                int d = calcd(zc.first,zc.second,oc.first,oc.second);
                curm = min(d,curm);
            }
            ans = max(ans,curm);
        }
        return ans;
    }
};