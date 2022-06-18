#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        generator(1,n,'(',"",1,0); 
        return ans;
    }

    void generator(int i,int n,char c,string str,int counto,int countc){
        str.push_back(c);
        if(i==n*2) ans.push_back(str);
        if(counto < n) generator(i+1,n,'(',str,counto+1,countc);
        if(countc < counto && countc < n){
            generator(i+1,n,')',str,counto,countc+1);
        }
    }
};