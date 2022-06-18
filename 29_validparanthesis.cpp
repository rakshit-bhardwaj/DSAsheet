#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> chars;
        map<char,char> closetoopen = { {')','('},{'}','{'},{']','['}};
        for (int i=0;i<s.size();i++){
            auto it = closetoopen.find(s[i]);
            if(it!=closetoopen.end()){
                if(chars.size()>0 && it->second==chars.top()){
                    chars.pop();
                }else{
                    return false;
                }
            }
            else {
                chars.push(s[i]);
            }
        }
        return chars.size()>0 ? false : true;
    }
};