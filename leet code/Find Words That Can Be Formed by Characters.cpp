

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.


    ***********************************************************
*/

    
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> f(26,0);
        int ans = 0;
        for(auto &x: chars) f[x-'a']++;
        for(auto &z: words){
            vector<int> wf(26,0);
            bool fl = true;
            for(auto &x: z) { wf[x-'a']++; }
            for(int i = 0; i < 26; i++) if(f[i] < wf[i]) {fl = false; break;}
            if(fl) ans+= z.length();
        }
        return ans;
    }
};