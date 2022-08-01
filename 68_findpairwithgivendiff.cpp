#include<bits/stdc++.h>
using namespace std;

void findpair(vector<int> arr,int x){
    map<int,int> freq;
    int n = arr.size();
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
        if(n==0 && freq[arr[i]]>1){
            cout<<"pair found => {"<<arr[i]<<", "<<arr[i]<<"}";
            return;
        }
        if(n==0){
            cout<<"pair not found";
            return;
        }
        if(freq.find(abs(arr[i] - x))!=freq.end()){
                cout<<"pair found => {"<<arr[i]<<", "<<abs(arr[i] - x)<<"}";
                return;
            }   
    }
    cout<<"pair not found";
}

int main () {
    vector<int> arr = {5, 20, 3, 2, 50, 80};
    int x = 78;
    findpair(arr,x);
    return 0;
}