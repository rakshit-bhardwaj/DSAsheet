#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev =0;bool c=false;
        if(x==INT_MIN) return 0;
        if(x<0){
            c = true;
            x*=-1;
        }
        while(x!=0){
            if(rev > INT_MAX/10) return 0;
            rev = rev*10 + x%10;
            x/=10;
        }
        if(c) rev*=-1;
        return rev;
    }
};

int main () {
    Solution obj;
    cout<<obj.reverse(123);
    return 0;
}