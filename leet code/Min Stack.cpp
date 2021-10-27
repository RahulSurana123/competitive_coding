

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.


    ***********************************************************
*/


#include <bits/stdc++.h>
class MinStack {
public:
    
    stack<int> x;
    int m = INT_MAX;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(m >= val){
            x.push(m);
            m = val;
        }
        x.push(val);
    }
    
    void pop() {
        if(x.top() == m){
            x.pop();
            m = x.top();
        }
        x.pop();
    }
    
    int top() {
        return x.top();
    }
    
    int getMin() {
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */