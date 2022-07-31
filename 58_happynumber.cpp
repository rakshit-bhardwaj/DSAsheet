#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        map<int,int> al;
        long sum=n;
        if(n==1) return true;
        while(sum!=1){
            int x = sum;
            sum=0;
            while(x!=0){
                sum+=(x%10)*(x%10);
                x/=10;
            }
            al[sum]++;
            if(al[sum]>1) return false;
        }
        return true;
    }
};

int main (){
    Solution obj;
    cout<<obj.isHappy(19);
}