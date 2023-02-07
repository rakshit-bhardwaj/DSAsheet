#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());

        queue<string> q;
        q.push(beginWord);
        int seq=1;
        while(!q.empty()){
            int size = q.size();
            while(size --){
                string cur = q.front();
                if(cur==endWord) return seq;
                q.pop();
                s.erase(cur);
                for(int i =0;i<cur.size();i++){
                    string temp = cur;
                    for(int j =0;j<26;j++){
                        temp[i] = 'a' + j;
                        if(s.find(temp)!=s.end()){
                            q.push(temp);
                        }
                    }
                }
            }
                
            seq++;
        }
        return 0;
    }
};