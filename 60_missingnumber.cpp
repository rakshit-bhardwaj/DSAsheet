#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int t=nums.size();
        for(int i=0;i<nums.size();i++){
            t+=i;
            t-=nums[i];
        }
        return t;
    }
};