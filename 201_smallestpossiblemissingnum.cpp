#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        if(n==1 && arr[0]!=1) return 1; 
        for(int i =0;i<n;i++) if(arr[i]<0) arr[i] = 0;
        for(int i =0;i<n;i++){
            int ind = abs(arr[i]) - 1;
            if(ind < 0 || ind >=n || arr[ind] < 0) continue;
            if(arr[ind]==0) arr[ind] = n+10;
            arr[ind] = arr[ind] * -1;
        }
        
        for(int i = 1;i<=n;i++){
            if(arr[i-1] >= 0) return i;
        }
        return n+1;
    } 
};