#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        vector<int> a;
        if (x < 0)
            return false;
        while (x != 0)
        {
            a.push_back(x % 10);
            x /= 10;
        }
        int i = 0, j = a.size() - 1;
        while (i < a.size() && j >= 0)
        {
            if (a[i] != a[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};