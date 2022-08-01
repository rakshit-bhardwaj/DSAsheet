#include<bits/stdc++.h>
using namespace std;

void checkpermute(vector<int> a,vector<int> b,int k){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());
    for(int i=0;i<a.size();i++){
        if(a[i] + b[i] < k){
            cout<<"NO\n";
            return;
        } 
    }
    cout<<"YES\n";
}

int main () {
    vector<int> a = {2, 1, 3}; 
    vector<int> b = {7, 8, 9}; 
    int k = 10; 
    checkpermute(a,b,k);
    return 0;
}