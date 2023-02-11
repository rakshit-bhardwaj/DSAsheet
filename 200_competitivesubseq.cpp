#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int rem = nums.size() - k;
        for(auto x : nums){
            while(ans.size() && rem && ans.back() > x){
                ans.pop_back();
                rem--;
            }
            ans.push_back(x);
        }

        while(rem){
            ans.pop_back();
            rem--;
        }
        return ans;
    }
};