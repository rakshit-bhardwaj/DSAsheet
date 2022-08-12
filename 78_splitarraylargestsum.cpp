#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> nums, int x, int m, int &ans)
    {
        int cursum = 0, maxsum = INT_MIN,c=0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(cursum+nums[i]>x){
                c++;
                cursum=0;
            }
            cursum += nums[i];
        }
        if (c+1 <= m) return true;
        return false;
    }
    void binarysearch(vector<int> nums, int s, int e, int x, int &ans)
    {
        if (s <= e)
        {
            int m = s + (e-s)/2;
            if (check(nums, m, x, ans))
            {
                ans = m;
                binarysearch(nums, s, m-1, x, ans);
            }
            else
            {
                binarysearch(nums, m+1, e, x, ans);
            }
        }
    }
    int splitArray(vector<int> &nums, int m)
    {
        int s = INT_MIN, e =0, ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > s)
                s = nums[i];
            e += nums[i];
        }
        ans = e;
        if(m==1) return ans;
        binarysearch(nums, s, e, m, ans);
        return ans;
    }
};
