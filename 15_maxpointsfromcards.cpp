#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0,maxsum=INT_MIN,k1,j,total,tot;
        tot = accumulate(cardPoints.begin(),cardPoints.end(),0);
        if(cardPoints.size()==k){
            return tot;
        }
        int s = 0,e = cardPoints.size()-k;
        total = accumulate(cardPoints.begin()+e,cardPoints.end(),0);
        maxsum = total;
        while(e<cardPoints.size()){
            cout<<total<<" "<<cardPoints[s]<<" "<<cardPoints[e]<<endl;
            total += cardPoints[s]-cardPoints[e];
            maxsum = max(maxsum,total);
            s++;
            e++;
        }
        return maxsum;
    }
};

// O(2^n)
// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int s=0,e=cardPoints.size()-1,sum,maxsum=INT_MIN;
//         maxsum=sums(cardPoints,k,0,s,e);
//         return maxsum;

//     }
     
//     int sums(vector<int>& cardPoints, int k,int sum,int s,int e){
//         if(k>0){
//             return max(sums(cardPoints,k-1,sum+cardPoints[s],s+1,e),sums(cardPoints,k-1,sum+cardPoints[e],s,e-1));
//         }
//         return sum;
//     }

// };

