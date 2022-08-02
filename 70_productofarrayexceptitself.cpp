#include<bits/stdc++.h>
using namespace std;

vector<int> product(vector<int> arr){
    int n = arr.size(),mul;
    vector<int> prod(n,1);
    mul = arr[0];
    for(int i=1;i<n;i++){
        prod[i] = mul * prod[i];
        mul *=arr[i];
    }
    mul = arr[n-1];
    for(int i=n-2;i>=0;i--){
        prod[i] = mul * prod[i];
        mul *= arr[i]; 
    }
    return prod;
}

void findpro(vector<int> arr){
    vector<int> prod = product(arr);
    for(int i=0;i<prod.size();i++){
        cout<<prod[i]<<" ";
    }
}

int main () {
    vector<int> arr = {10, 3, 5, 6, 2};
    findpro(arr);
    return 0;
}