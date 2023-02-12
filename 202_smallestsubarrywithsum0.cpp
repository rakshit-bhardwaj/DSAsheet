#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
       map<int,int> prefix;
       int maxi = 0,cursum = 0;

       for(int i =0;i<n;i++){
        cursum += A[i];
        if(cursum == 0) maxi = i+1;
        else {
            if(prefix.find(cursum) != prefix.end()) maxi = max(maxi, i - prefix[cursum]);
            else  prefix[cursum] = i;
        }
       }
       return maxi;
    }
};