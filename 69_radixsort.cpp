#include<bits/stdc++.h>
using namespace std;

void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int getmax(int arr[],int n){
    int m = arr[0];
    for(int i = 1;i<n;i++){
        if(arr[i]>m) m = arr[i];
    }
    return m;
}

int countsort(int arr[],int exp,int n){
    vector<int> out(n),count(10,0);
    for(int i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i] += count [i-1];
    }
    for(int i=n-1;i>=0;i--){
        cout<<"i = "<<i<<" placing "<<arr[i]<<" at index "<<count[(arr[i]/exp)%10] - 1<<endl;
        out[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--; 
    }
    for(int i=0;i<n;i++){
        arr[i] = out[i];
    }
    printarr(arr,n);
}

void radixsort(int arr[],int n){
    int m = getmax(arr,n);
    for(int exp = 1;m/exp>0;exp*=10){
        countsort(arr,exp,n);
    }
}


int main () {
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(int);
    radixsort(arr,n);
}