#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,s,b=-1,profit=0;
        for(i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1] && b==-1){
                b=i-1;
            }
            if(prices[i]<prices[i-1] && b!=-1){
                s=i-1;
                profit += prices[s] - prices[b];
                b=-1;
            }
            if(i == prices.size()-1 && b!=-1){
                profit += prices[i] - prices[b];
            }
        }
        return profit;
    }
};