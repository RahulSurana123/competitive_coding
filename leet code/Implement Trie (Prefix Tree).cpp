

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.

void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Trie {
public:
    
    Trie* child[26];
    bool iw = false;
    
    // Trie() {
    //     this -> iw = false;
    // }
    
    void insert(string word) {
        Trie* z = this;
        for(auto x: word){
            if(z->child[x-'a'] == nullptr)
                z->child[x-'a'] = new Trie();
            z = z -> child[x-'a'];
        }
        z->iw = true;
    }
    
    bool search(string word) {
        Trie* z = this;
        for(char x: word){
            if(z->child[x-'a'] == nullptr) return false;
            z = z -> child[x-'a'];
        }
        return z->iw;
    }
    
    bool startsWith(string prefix) {
        Trie* z = this;
        for(auto x: prefix){
            if(z->child[x-'a'] == nullptr) return false;
            z = z -> child[x-'a'];
        }
        return true; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */