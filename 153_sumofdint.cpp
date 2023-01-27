#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> subs,ans;
    vector<vector<int>> bedges;
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        subs.resize(n,1);ans.resize(n,0);
        bedges.resize(n);
        for(int i = 0;i<edges.size();i++){
            bedges[edges[i][0]].push_back(edges[i][1]);
            bedges[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(0);
        helper(0);
        return ans;
    }

    void dfs(int c,int par = -1){
        for(auto x : bedges[c]){
            if(x == par) continue;
            dfs(x,c);
            subs[c] += subs[x];
            ans[c] += ans[x] + subs[x];
        }
    }

    void helper(int c,int par = -1){
        for(auto x : bedges[c]){
            if(x == par) continue;
            ans[x] = ans[c] - subs[x] + (bedges.size() - subs[x]);
            helper(x,c);
        }
    }

};

int main () {
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    int n = 6;
    Solution s;
    vector<int> ans;
    ans = s.sumOfDistancesInTree(n,edges);
    for(auto x : ans){
        cout<<x<<" ";
    }
    return 0;
}