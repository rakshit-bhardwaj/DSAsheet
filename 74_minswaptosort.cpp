#include<bits/stdc++.h>
using namespace std;

int minswap(vector<int> arr){
    int ms=0,n = arr.size(),cycle;
    map<int,int> ind;
    for(int i=0;i<n;i++){
        ind[arr[i]] = i;
    }
    sort(arr.begin(),arr.end());
    bool visited[n] = {0};
    for(int i=0;i<n;i++){
        if(visited[i] || ind[arr[i]] == i) continue;
        cycle = 0; int j = i;
        while(!visited[j]){
            visited[j]=1;
            j = ind[arr[j]];
            cycle++;
        }
        if(cycle>0) ms += cycle-1;
    }
    return ms;
}

int main (){
    vector<int> arr = {1,5,4,3,2};
    cout<<minswap(arr); 
}