

/* 

    Solution by Rahul Surana

    ***********************************************************

You have a browser of one tab where you start on the homepage and you can visit another url, 
get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.

void visit(string url) Visits url from the current page. It clears up all the forward history.

string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, 
you will return only x steps. 
Return the current url after moving back in history at most steps.

string forward(int steps) Move steps forward in history. 
If you can only forward x steps in the history and steps > x, you will forward only x steps. 
Return the current url after forwarding in history at most steps.



    ***********************************************************
*/


#include <bits/stdc++.h>
class BrowserHistory {
public:
    stack<string> a,b;
    BrowserHistory(string homepage) {
        a.push(homepage);    
    }
    
    void visit(string url) {
        a.push(url);
        b = stack<string>();
    }
    
    string back(int steps) {
        while(a.size()>1&&steps--){
            b.push(a.top());
            a.pop();
        }
        return a.top();
    }
    
    string forward(int steps) {
         while(!b.empty()&&steps--){
            a.push(b.top());
            b.pop();
        }
        return a.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */