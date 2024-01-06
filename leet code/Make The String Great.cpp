

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. 
You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    string makeGood(string s) {
        string copy = "";
        stack<char> q;
        q.push(s[0]);
        for(int i = 1; i < s.length(); i++){
            if(q.size()>0){
                char x = q.top();
                if((isupper(x) && s[i] == tolower(x)) || (toupper(x)==s[i] && islower(x))){
                    q.pop();
                }
                else{
                    q.push(s[i]);
                }
            }
            else{
                q.push(s[i]);
            }
        }
        string ans;
        while(q.size()){ ans += q.top(); q.pop();}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};