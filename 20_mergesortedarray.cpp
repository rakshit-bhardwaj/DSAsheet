#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int ptr1 = 0, ptr2 = 0, cn = min(m, n), main = 0, temp, itr;
        while (cn--)
        {
            if (nums1[ptr1] > nums2[ptr2])
            {
                swap(nums1[ptr1], nums2[ptr2]);
            }
            ptr1++;
            itr = ptr2;
            while (nums2[itr] > nums2[itr + 1])
            {
                swap(nums2[itr], nums2[itr + 1]);
                itr++;
                if (itr == n - 1)
                    break;
            }
        }
        for (int i = m; i < m + n; i++)
        {
            nums1[i] = nums2[i - n];
        }
    }
};