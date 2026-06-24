

/* 
    Solution by Rahul Surana
    
    ***********************************************************

Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.


    ***********************************************************
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> f;
        for(auto x: text){
            f[x]++;
        }
        int m = 1e9;
        m = min(f['b'],m);
        m = min(f['a'],m);
        m = min(f['n'],m);
        // m = min(f['s'],m);
        m = min(f['l']/2,m);
        m = min(f['o']/2,m);
        return m;
    }
};
