#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b){
        string ans;
        int carry = 0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(int i=0;i<max(a.size(),b.size());i++){
            int x = i < a.size() ? a[i] - '0' : 0;
            int y = i < b.size() ? b[i] - '0' : 0;
            int total = x + y + carry;
            char c = total % 2 + '0';
            carry = total / 2;
            string temp = ans;
            ans.clear();
            ans.push_back(c);
            ans.append(temp);
        }
        if(carry){
            string temp = ans;
            ans.clear();
            ans.push_back('1');
            ans.append(temp);
        }
        return ans;
    }
};

int main()
{
    string a = "1010", b = "1011";
    Solution obj;
    cout << obj.addBinary(a, b);
    return 0;
}