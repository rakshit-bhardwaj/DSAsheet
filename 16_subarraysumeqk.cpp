#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0,cursum=0;
        unordered_map<int,int> freq;
        freq[0]++;
        vector<int> prefixsum;
        for(int i=0;i<nums.size();i++){
            cursum += nums[i];
            if(freq.find(cursum-k)!=freq.end()) ans += freq[cursum-k];
            freq[cursum]++;
        }

        return ans;
    }
};