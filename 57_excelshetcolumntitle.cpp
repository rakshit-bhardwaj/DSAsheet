#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber>0){
            columnNumber-=1;
            ans = char(columnNumber%26 + 'A') + ans;
            columnNumber/=26;
        }
        return ans;
    }
};

int main () {
    int n = 1123;
    Solution obj;
    cout<<obj.convertToTitle(n);
    return 0;
}