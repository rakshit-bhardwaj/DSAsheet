#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int s = needle.size();
        if(s==0) return 0;
        if(haystack.size()==s){
            return haystack == needle ? 0 : -1;
        }
        if(needle.size()>haystack.size()) return -1;
        int end = haystack.size()-s;
        //if(s==1) end++;
        for(int i=0;i<=end;i++){
            if(i+s>haystack.size()) break;
            cout<<haystack.substr(i,s)<<" ";
            if(haystack.substr(i,s)==needle){
                return i;
            }
        }
        return -1;
    }
};