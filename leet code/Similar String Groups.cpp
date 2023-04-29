
/*


Solution By Rahul Surana


***********************************


Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. 
Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), 
and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  
Notice that "tars" and "arts" are in the same group even though they are not similar.  
Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. 
How many groups are there?
 


*************************************/



#include<bits/stdc++.h>

class Solution {
public:
    
    vector<int> p;
    
    int fp(int a){
        if(a == p[a]) return a;
        return p[a] = fp(p[a]);
    }
    
    int numSimilarGroups(vector<string>& strs) {
        p.clear();
        p.resize(strs.size());
        for(int i = 0; i < strs.size(); i++) p[i]=i;
        for(int i = 0; i < strs.size(); i++) {
            for(int j = i+1; j < strs.size(); j++) {
                bool isAn = true;
                for(int k =0; k < strs[i].length();k++){
                    if(strs[i][k]!= strs[j][k]){
                        int x = k+1;
                        while(x < strs[i].length()){
                        if(strs[i][k] == strs[j][x] && strs[j][k] == strs[i][x]) break;
                            x++;
                        }
                        swap(strs[j][x],strs[j][k]);
                        if(strs[i] != strs[j]) {    
                            isAn = false;
                        }
                        swap(strs[j][x],strs[j][k]);
                        break;   
                    }
                }
                if(isAn){
                    int a = fp(i),b = fp(j);
                    p[a] = b;
                }
            }
        }
        set<int> s;
        for(auto x: p){
            int q = fp(x);
            s.insert(q);
        }
        return s.size();
    }
};