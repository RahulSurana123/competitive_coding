


/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

Return the number of special letters in word.

    ***********************************************************
*/



class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int> c;
        int ans = 0;
        for(auto x:word) c[x]++;

        for(int i = 0; i < 26; i++){
            if(c.count(i+'a') && c.count(i+'A')) ans++;
        } 
        return ans;
    }
};