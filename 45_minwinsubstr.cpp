#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(map<char,int> f1,map<char,int> f2){
        for(auto c: f1){
            if(c.second>f2[c.first]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        map<char,int> f1,f2;
        pair<int,int> win=make_pair(0,INT_MAX);
        char rem;
        bool c1,c2;
        int i,j;
        if(t.size()>s.size()) return "";
        for(i=0;i<t.size();i++){
            f1[t[i]]++;
            f2[s[i]]++;
        }
        i=0;j=t.size();
        c1=false;c2=false;
        while(i<s.size() || j<s.size()){
            if(!c2){
                c1 = check(f1,f2);
            }
            if(c1){
                c2 = true;
                if(j-i<win.second - win.first){
                    win.first = i;
                    win.second = j;
                }
                f2[s[i]]--;
                if(f2[s[i]]<f1[s[i]]) c1=false;
                rem = s[i];
                i++; 
            } else if(j<s.size()) {
                f2[s[j]]++;
                if(s[j]==rem){
                    if(f1[rem]<=f2[rem]) c1= true;
                }
                j++;
            } else break;
        }
        if(win.second == INT_MAX) return "";
        string ans = s.substr(win.first,win.second-win.first);
        return ans;
    }
};

int main () {
    Solution obj;
    string s = "ADOBECODEBANC", t = "ABC";
    cout<<obj.minWindow(s,t);
    return 0;
}