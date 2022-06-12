#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if(nums.size()==1) return true;
        vector<int> pos;
        bool  check = false;
        int minin;
        int x = nums.size()-1;
        while (true)
        { 
            check = false;
            for (int i = x - 1; i >= 0; i--)
            {
                if (nums[i] + i>= x) {check = true; minin = i; pos.push_back(i);}
            }
            if(!check) return false;
            x = minin;
            if(minin==0) return true;
        }
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {3, 2, 1, 0, 4};
    cout << obj.canJump(nums);
    return 0;
}