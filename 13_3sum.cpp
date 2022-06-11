#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n<3) return ans;
        
        sort(nums.begin(), nums.end()); //[-4,-1,-1,0,1,2]
        for(int i = 0; i<n-2; i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                
                int l = i+1, h = nums.size()-1, sum = 0-nums[i];
                while(l<h){
                    if(nums[l]+nums[h]==sum){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);

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
        
        
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = obj.threeSum(a);
    // cout<<"flag 1";
    // cout<<ans.size();
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            // cout<<"flag 1";
            cout << ans[i][j] << " ";
        }
        cout << "] ";
    }
    return 0;
}