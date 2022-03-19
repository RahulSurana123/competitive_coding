

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.



    ***********************************************************
*/


#include <bits/stdc++.h>

class FreqStack {
public:
    
    map<int,int> m;
    priority_queue<pair<int,pair<int,int>>> pq;
    int k;
    
    FreqStack() {    
        k = 0;
        // m[-1] = stack<int>();
    }
    
    void push(int val) {
        m[val]++;
        pq.push({m[val],{k++,val}});
    }
    
    int pop() {
        auto x = pq.top();
        pq.pop();
        m[x.second.second]--;
        return x.second.second;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */