#include<bits/stdc++.h>
using namespace std;

bool checksort(vector<int> arr){
    for(int i=1;i<arr.size();i++){
        if(arr[i]<arr[i-1]) return false;
    }
    return true;
}

int mincost (vector<int> arr) {
    if(!checksort(arr)) sort(arr.begin(),arr.end());
    int n = arr.size(),y;
    if(n%2!=0) y = arr[n/2];
    else y = (arr[n/2] + arr[n/2 - 1])/2;
    int cost = 0;
    for(int i=0;i<n;i++){
        cost += abs(y - arr[i]);
    }
    return cost;
}

int main () {
    vector <int> arr = {1,100,101};
    cout<<mincost(arr);
}
