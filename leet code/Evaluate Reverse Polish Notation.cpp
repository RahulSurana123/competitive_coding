

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.


    ***********************************************************
*/


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto x: tokens){
            int d = 0;
            if(x.length() ==1 && (x[0] == '+' || x[0] == '-' || x[0] == '*' ||x[0] == '/')) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                // cout << b <<" "<< x <<" "<<a <<"\n";
                if(x == "+") { s.push(a+b); }
                else if(x == "/"){ s.push(b/a); }
                else if(x == "*"){ s.push(a*b); }
                else if(x == "-"){ s.push(b-a); }
            }
            else{
                int d = 0;
                bool neg = false;
                for(auto z: x) { if(z >= '0' && z <= '9') { d*=10; d +=z-'0'; } else neg = true; }
                s.push( (neg? -1 : 1) * d); 
            }
        }
        return s.top();
    }
};