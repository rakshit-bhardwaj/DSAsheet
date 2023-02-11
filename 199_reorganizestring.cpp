#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> m;
        priority_queue<pair<int,char>> q;
        
        string ans;
        for(auto c : s) m[c]++;
        for(auto x : m) q.push({x.second,x.first});

        while(q.size() > 1){
            auto top1 = q.top(); q.pop();
            auto top2 = q.top(); q.pop();

            ans+=top1.second; ans+= top2.second;

            if(top1.first > 1) q.push({top1.first - 1,top1.second});
            if(top2.first > 1) q.push({top2.first - 1,top2.second});
        }

        if(!q.empty()){
            if(q.top().first>1) return "";
            else ans += q.top().second;
        }
        return ans;
    }
};