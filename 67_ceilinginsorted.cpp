#include<bits/stdc++.h>
using namespace std;

int binarysearch(int s,int e,vector<int> arr,int x){
    if(s<e){
        int m = (s+e)/2;
        if(arr[m]==x) return m;
        else if(arr[m]>x) return binarysearch(s,m,arr,x);
        else return binarysearch(m,e,arr,x);
    }
    return -1;
}

int main () {
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    if(arr.size()<=1){
        cout<<"no floor\nno ceiling";
        return 0; 
    }
    int x = 10;
    int ind = binarysearch(0,arr.size(),arr,x);
    if(ind == 0){
        cout<<"no floor\n"<<"ceiling = "<<arr[ind+1];
    }
    if(ind == arr.size()-1){
        cout<<"floor = "<<arr[ind-1]<<"\nno ceiling";
    }
    else cout<<"floor = "<<arr[ind-1]<<"\nceling = "<<arr[ind +1];
    return 0;
}