

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given two string arrays, queries and dictionary. All words in each array comprise of lowercase English letters and have the same length.

In one edit you can take a word from queries, and change any letter in it to any other letter. Find all words from queries that, after a maximum of two edits, equal some word from dictionary.

Return a list of all words from queries, that match with some word from dictionary after a maximum of two edits. Return the words in the same order they appear in queries.


    ***********************************************************
*/

class Solution {
public:

    bool diff(string a, string b){
        int ans = 0;
        for(int i = 0; i < a.length(); i++){
            if(a[i] != b[i]) ans++;
            if(ans>2) break;
        }
        return ans<=2;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        vector<string> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < dictionary.size(); j++){
                if(diff(queries[i], dictionary[j])){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
