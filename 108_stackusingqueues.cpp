#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue <int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.empty()) return -1;
        int num = q1.back();

        while(q1.size() > 1){
            q2.push(q1.front()); q1.pop();
        }
        if(!q1.empty()) q1.pop();
        while(!q2.empty()){
            q1.push(q2.front()); q2.pop();
        }
        return num;
    }
    
    int top() {
        if(q1.empty()) return -1;
        while(!q1.empty()){
            q2.push(q1.front()); q1.pop();
        }
        int num = q2.back();
        while(!q2.empty()){
            q1.push(q2.front()); q2.pop();
        }
        return num;
    }
    
    bool empty() {
        return q1.empty();
    }
};