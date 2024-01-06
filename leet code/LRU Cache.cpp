

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. 
Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, 
evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.


    ***********************************************************
*/


class LRUCache {
public:

    
    unordered_map<int, int> mv;
    set<pair<int,int>> s;
    unordered_map<int, int> vals;
    int cap = 0, id = 0;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mv.count(key)) {
            int v = vals[key];
            s.erase({v,key});
            id++;
            s.insert({id,key});
            vals[key] = id;
            return mv[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(!mv.count(key)){
            if(cap == mv.size()){
                int r = s.begin()->second;
                vals.erase(r);
                mv.erase(r);
                s.erase(s.begin());
            }
            id++;
            mv[key] = value;
            vals[key] = id;
            s.insert({id,key});
        }
        else{
            int v = vals[key];
            s.erase({v,key});
            id++;
            s.insert({id,key});
            vals[key] = id;
            mv[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */