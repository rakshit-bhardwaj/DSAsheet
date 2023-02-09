#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int,int> frq;
    priority_queue <pair<int,int>> q;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        for(auto x : nums) frq[x]++;
        for(auto x : frq) q.push({x.second,x.first});
        for(int i =0;i<k;i++){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }

};