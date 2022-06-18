#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        string r = s;
        int c=0;
        reverse(r.begin(),r.end());
        if(r==s) return true;
        int i=0,j=s.size()-1;
        while(i<j){
            if(c>1) return false;
            if(s[i]!=s[j]){
                string temp = s.substr(i+1,j-i);
                string temp2 = temp;
                cout<<temp<<" "<<temp2<<endl;
                reverse(temp2.begin(),temp2.end());
                if(temp==temp2) return true;
                if(temp!=temp2){
                    temp = s.substr(i,j-i);
                    temp2 = temp;
                    reverse(temp2.begin(),temp2.end());
                    if(temp!=temp2) return false;
                    else return true;
                }
                c++;   
            }
            i++;j--;
        }
        return true;
    }
};

// 0 1 2 3 4 5 
// a a a a z a
// a b c a