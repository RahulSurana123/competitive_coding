

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given a string s. We want to partition the string into as many parts as possible 
so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> f(26,0);
        for(int i = 0; i < s.length(); i++){
            f[s[i]-'a']++;
        }
        vector<int> ans;
        int i = 0,last = 0;
        int su = 0;
        while(i < s.length()){
            while(last < s.length()&& i < s.length() && f[s[i]-'a']) f[s[last++]-'a']--;
            i++;
            if(last == i) {
                if(ans.size() == 0) { ans.push_back(last); su = last; }
                else{
                    ans.push_back(last-su);
                    su += last-su;
                }
            }
        }
        return ans;
    }
};