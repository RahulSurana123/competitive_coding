

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


    ***********************************************************
*/



class Solution {
public:

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return vector<string>();
        vector<string> d = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i = 0; i < d[digits[0]-'2'].size(); i++) ans.push_back( string(1,d[digits[0]-'2'][i]) );
        for(int i = 1; i < digits.size(); i++){
            string x = d[digits[i]-'2'];
            vector<string> temp;
            for(int j = 0; j < ans.size(); j++){
                for(int k = 0; k < x.length(); k++){
                    temp.push_back(ans[j] + x[k]);
                }
            }         
            ans = temp;
        }
        return ans;
    }
};