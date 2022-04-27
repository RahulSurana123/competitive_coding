

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 
2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    
    int parent(int u, vector<int> &p){
        if(p[u] == u) return u;
        return p[u] = parent(p[p[u]],p);
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {  
        vector<int> p(s.length()+1,0);
        map<int,vector<int>> m;
        map<int,int> mi;
        for(int i = 0 ; i < s.length(); i++) p[i] = i;
        for(int i = 0 ; i < pairs.size(); i++){
            int a = parent(pairs[i][0],p);
            int b = parent(pairs[i][1],p);
            p[a] = b;
        }
        for(int i = 0 ; i < s.length(); i++){
            int a = parent(i,p);
            m[a].push_back(i);
            mi[a] = 0;
        }
        for(auto &x: m){
            sort(x.second.begin(),x.second.end(),[&](int a, int b){ return s[a]<s[b]; });
            // for(auto z: x.second) cout << z <<" ";
            // cout << "\n";
        }
        string ans;
        for(int i = 0 ; i < s.length(); i++){
            int a = parent(i,p);
            ans += s[m[a][mi[a]]];
            // cout << m[a][mi[a]] <<" "<< mi[a]<<" ";
            mi[a]++;
            // m[a].erase(m[a].begin());
        }
        return ans;
    }
};