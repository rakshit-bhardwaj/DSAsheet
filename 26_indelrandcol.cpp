#include<bits/stdc++.h>
using namespace std;

class RandomizedCollection {
public:
    vector<int> multiset;
    map<int,int> freq;
    map<int,set<int>> f_ind;
    RandomizedCollection() {}
    
    bool insert(int val) {
        bool check=false;
        if(freq[val]==0) check=true; 
        f_ind[val].insert(multiset.size());
        multiset.push_back(val);
        freq[val]++;
        return check;
    }
    
    bool remove(int val) {
        bool check = true;
        if(freq[val]==0) check = false;
        else {
           freq[val]--; 
           auto it = f_ind[val].begin();
           int pos = *it;
           f_ind[val].erase(pos);
           if(f_ind[val].size()==0){
            f_ind.erase(val);
           } 
           if (pos == multiset.size()-1){
            multiset.pop_back();
           }else {
            int temp = multiset.back();
            f_ind[temp].erase(multiset.size()-1);
            f_ind[temp].insert(pos);
            multiset[pos] = temp;
            multiset.pop_back();
           }
           
        }
        return check;
    }
    
    int getRandom() {
        return multiset[rand() % multiset.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */