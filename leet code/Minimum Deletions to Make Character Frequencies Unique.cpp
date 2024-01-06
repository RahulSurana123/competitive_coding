

/* 

    Solution by Rahul Surana
    
    ***********************************************************


A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. 
For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

    ***********************************************************
    
*/

class Solution {
public:

    
    int minDeletions(string s) {
        vector<int> f(26,0);
        for(auto x: s) f[x-'a']++;
        set<int> vis;
        int ans = 0;
        for(int i = 0 ; i < 26;i++){
            while(f[i] > 0 && vis.count(f[i])){ ans++; f[i]--; }\
            if(f[i] == 0) continue;
            vis.insert(f[i]); 
        }
        return ans;
    }
};