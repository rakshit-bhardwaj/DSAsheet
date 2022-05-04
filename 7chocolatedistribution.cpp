#include<bits/stdc++.h>
using namespace std;
int distrbution(vector<int> arr,int m){
    int temp,dif,j,mindif=INT_MAX;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        dif = abs(arr[i] - arr[i+m-1]);
        mindif = min(dif,mindif);
    }
    return mindif;
}
int main(){
    vector<int> arr = {7, 3, 2, 4, 9, 12, 56};
    int m = 3;
    cout<<"minimum difference is -> "<<distrbution(arr,m); 
    return 0;
}