



/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.

 

    ***********************************************************
*/



class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> st;
        int i = 0;
        for(int i = 0;i < s.length();i++){
            string k = "";
            if(s[i]!=' '){
                while(i < s.length() && (s[i] !=' ')){
                    k+=s[i];
                    i++;
                }
                st.push_back(k);
            }
        }
        for(int j = 0; j < st.size()/2; j++){
            swap(st[j],st[st.size()-1-j]);
        }
        string ans;
        ans += st[0];
        for(int j = 1; j < st.size(); j++){
            ans += " " + st[j];
        }
        return ans;
    }
};