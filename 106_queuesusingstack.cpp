#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        this->s1.push(x);
    }

    int pop()
    {
        if (this->s1.empty())
            return -1;
        while (!this->s1.empty())
        {
            this->s2.push(this->s1.top());
            this->s1.pop();
        }
        int num = this->s2.top();
        this->s2.pop();
        while (!this->s2.empty())
        {
            this->s1.push(this->s2.top());
            this->s2.pop();
        }
        return num;
    }

    int peek()
    {
        if (this->s1.empty())
            return -1;
        while (!this->s1.empty())
        {
            this->s2.push(this->s1.top());
            this->s1.pop();
        }
        int num = this->s2.top();
        while (!this->s2.empty())
        {
            this->s1.push(this->s2.top());
            this->s2.pop();
        }
        return num;
    }

    bool empty()
    {
        return this->s1.empty();
    }
};