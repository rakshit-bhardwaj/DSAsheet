#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int> (n,INT_MAX/2));
        for(int i =0;i<n;i++) dist[i][i] = 0;
        for(auto x : edges){
            dist[x[0]][x[1]] = x[2];
            dist[x[1]][x[0]] = x[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j =0;j<n;j++){   
                    dist[i][j] = min(dist[i][j],(dist[i][k] + dist[k][j]));
                }
            }
        }
        int ans;
        int leastcount=INT_MAX;
        for(int i =0;i<n;i++){
            int count =0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(dist[i][j]<=distanceThreshold) count++;
            }
            if(count<leastcount){
                leastcount = count;
                ans = i;
            } else if(count == leastcount && i > ans) ans = i;
        }
        return ans;
    }
};