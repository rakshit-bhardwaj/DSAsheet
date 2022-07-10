#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <string, vector<string>> m;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            m[temp].push_back(strs[i]);
        }
        for(auto it = m.begin();it!=m.end();it++){
            vector<string> s;
            for(int i=0;i<it->second.size();i++){
                s.push_back(it->second[i]);
            }
            ans.push_back(s);
        }
        return ans;
    }
};