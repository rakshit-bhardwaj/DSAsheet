#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<pair<int,int>,int> cache;
    int dfs(int i,int j,string s,string t){
        if(t.size()-j>s.size()-i) return 0;
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        auto it = cache.find({i,j});
        if(it!=cache.end()) return cache[{i,j}];

        if(s[i]==t[j]) cache[{i,j}] = dfs(i+1,j+1,s,t) + dfs(i+1,j,s,t);
        else cache[{i,j}] = dfs(i+1,j,s,t);

        return cache[{i,j}];
    }

    int numDistinct(string s, string t) {
        return dfs(0,0,s,t);
    }
};