#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>(nums.size()/2)) return nums[i];
        }
        return 0;
    }
};