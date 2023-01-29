#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string decodeString(string s) {
        string ans;
        string temp;
        int n;
        int num=0;
        for(int i =0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                num = num*10 + s[i] - '0';
                continue;
            }
            if(s[i]=='['){
                pair<string,int> t = recur(i+1,s,num);
                ans.append(t.first);
                i = t.second;
                num = 0;
                continue;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }

    pair<string,int> recur(int x,string s,int n){
        string adder;
        int num =0;
        for(int i =x;i<s.size();i++){
            if(s[i]==']'){
                string repeat;
                for(int j = 0;j<n;j++){
                    repeat.append(adder);
                }
                return {repeat,i};
            }
            if(s[i]>='0' && s[i]<='9'){
                num = num*10 + s[i] - '0';
                continue;
            }
            if(s[i]=='['){
                pair<string,int> t = recur(i+1,s,num);
                adder.append(t.first);
                i = t.second;
                num = 0;
                continue;
            }
            adder.push_back(s[i]);
        }
        return {"failed",-1};
    }
};