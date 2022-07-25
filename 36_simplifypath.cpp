#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string cur;
        stack<string> s;
        path = path + '/';
        string ans;
        for(auto c: path){
            if(c == '/'){
                if(cur==".." ){
                    if(!s.empty()){
                        s.pop();
                    }
                } 
                else if (cur != "" && cur!="."){
                    s.push(cur);
                }
                cur = "";
            }
            else {
                cur+=c;
            }
        }
        stack<string> s2;
        while(!s.empty()){
            s2.push(s.top());
            s.pop();
        }
        ans.push_back('/');
        while(!s2.empty()){
            ans.append(s2.top());
            ans.push_back('/');
            s2.pop();
        }
        if(ans.size()>1) ans.pop_back();
        return ans;
    }
};

int main () {
    string s = "/home//foo//hello/nice/boi";
    Solution Obj;
    cout<<Obj.simplifyPath(s);
    return 0;
}