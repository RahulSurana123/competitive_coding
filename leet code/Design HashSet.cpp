

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.



    ***********************************************************
*/



#include <bits/stdc++.h>

class MyHashSet {
public:
    
    set<int> s;
    
    MyHashSet() {
        
    }
    
    void add(int key) {
        s.insert(key);
    }
    
    void remove(int key) {
        auto x = find(s.begin(),s.end(),key);
        if(x!=s.end())
        s.erase(x);
    }
    
    bool contains(int key) {
        return s.count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */