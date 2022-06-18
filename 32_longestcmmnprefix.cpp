#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int cs = 0,ucs;
        string lcp;
        if(strs.size()==1){
            return strs[0];
        }
        for(int i=0;i<min(strs[0].size(),strs[1].size());i++){
            if(strs[0][i]!=strs[1][i]) break;
            cs ++;
            lcp.push_back(strs[0][i]);
        }
        if(strs.size()==2) return lcp;
        for(int i=2;i<strs.size();i++){
            ucs=0;
            for(int j=0;j<cs;j++){
                if(strs[i][j]!=lcp[j]) break;
                ucs++;
            }
            cs=ucs;
        }
        cout<<lcp<<" ";
        cout<<lcp.substr(0,cs)<<endl;
        return lcp.substr(0,cs);
    }
};