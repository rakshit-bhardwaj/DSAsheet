#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int sum,i,j,l,h;
        if(nums.size()<4) return ans;
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size()-3;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
            for(j=i+1;j<nums.size()-2;j++){
                if(j==i+1 || (j>i+1 && nums[j]!=nums[j-1])){
            
            int l = j+1, h = nums.size()-1, sum = target-nums[i]-nums[j];
                while(l<h){
                    if(nums[l]+nums[h]==sum){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);
                        sort(temp.begin(),temp.end());
                        ans.push_back(temp);  
                        while(l<h && (nums[l]==nums[l+1])) l++;
                        while(l<h && (nums[h]==nums[h-1])) h--;
                        l++; h--;
                    }
                    else if((nums[l]+nums[h]) < sum) l++;
                    else h--;
                } 
                }
            }
            }
        }
        return ans;
    }
};
