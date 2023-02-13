#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> ans;
        for(auto p : points) q.push({ -1 * (p[0]*p[0] + p[1]*p[1]),{p[0],p[1]}}); 
        while(!q.empty() && k--){
            auto cur = q.top();
            q.pop();
            vector<int> temp;
            temp.push_back(cur.second.first);
            temp.push_back(cur.second.second);
            ans.push_back(temp);
        }
            return ans;
    }
};