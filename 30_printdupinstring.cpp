#include<bits/stdc++.h>
using namespace std;

int main () {
    string str="test string";
    string dup;
    map<char,int> freq;
    for(auto c : str){
        freq[c]++;
        if(freq[c]>1){
            dup.push_back(c);
        }
    }
    cout<<"duplicate characters with their frequencies are -> ";
    for(auto c : dup){
        cout<<c<<" "<<freq[c]<<endl;
    }
    return 0;
}