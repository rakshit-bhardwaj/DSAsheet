#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        int c=0;
        for(int i=1;i*i<n;i++){
            if(n%i==0) c++;
            if(c==k) return i;
        }
        for(int i=int(sqrt(n));i>1;i--){
            if(n%i==0) c++;
            if(c==k) return n/i;
        }
        if(c==k-1){
            return n;
        }
        return -1;
    }
};