

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. 
If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, 
or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.



    ***********************************************************
*/



#include <bits/stdc++.h>

class MyHashMap {
public:
    
    map<int,int> m;
    
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        m[key] = value;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        return m[key];
    }
    
    void remove(int key) {
        if(m.find(key) != m.end()) m.erase(m.find(key));
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */