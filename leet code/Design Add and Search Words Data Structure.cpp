

/* 

    Solution by Rahul Surana

    ***********************************************************

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. 
word may contain dots '.' where dots can be matched with any letter.



    ***********************************************************
*/


#include <bits/stdc++.h>
class WordDictionary {
public:
    unordered_map<int,unordered_set<string>> m;
    WordDictionary() {
    }
    
    void addWord(string word) {
        m[word.length()].insert(word);
    }
    
    bool search(string word) {
        int l = word.length();
        if(word.find('.') == string::npos){
            return m[l].count(word);
        }
        for(auto a : m[l]){
            bool x = true;
            for(int i = 0; i < l; i++){
                if( word[i] != '.' && a[i] != word[i]){
                    x = false;
                    break;
                }
            }
            if(x)
            return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */