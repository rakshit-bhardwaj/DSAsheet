#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        long curno = 0, ans = 0;
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
                temp.push_back(s[i]);
        }
        s = temp;
        // cout<<s<<endl;
        stack<int> op;
        char opr = '+';
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                curno = curno * 10 + (s[i] - 48);
            }
            if (!(s[i] >= '0' && s[i] <= '9') || i == s.size() - 1)
            {
                if (opr == '+')
                {
                    op.push(curno);
                }
                else if (opr == '-')
                {
                    op.push(-curno);
                }
                else if (opr == '*')
                {
                    int x = op.top();
                    op.pop();
                    op.push(x * curno);
                }
                else if (opr == '/')
                {
                    int x = op.top();
                    op.pop();
                    op.push(x / curno);
                }
                curno = 0;
                opr = s[i];
            }
        }
        while (!op.empty())
        {
            ans += op.top();
            op.pop();
        }
        return ans;
    }
};

int main()
{
    string s = "42";
    Solution obj;
    cout << obj.calculate(s);
    return 0;
}