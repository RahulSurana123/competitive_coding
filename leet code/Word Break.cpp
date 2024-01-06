

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string s and a dictionary of strings wordDict, 
return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.


    ***********************************************************
*/

class Solution {
public:
    unordered_map<string,bool> m;
    bool df(string s, vector<string>& wd, string a){
        if(a.length() == s.length()) return a == s;
        if(m.count(a)) return m[a];
        for(int i = 0; i < wd.size(); i++){
            if((a.length()+wd[i].length()) <= s.length() && wd[i] == s.substr(a.length(),wd[i].length()) && df(s,wd,a+wd[i]))
            return m[a] = true;
        }
        return m[a] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return df(s,wordDict, "");
    }
};