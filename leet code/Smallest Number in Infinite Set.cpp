
/*


Solution By Rahul Surana


***********************************


You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

Implement the SmallestInfiniteSet class:

SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
int popSmallest() Removes and returns the smallest integer contained in the infinite set.
void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.
 


*************************************/



#include<bits/stdc++.h>

class SmallestInfiniteSet {

public:

    int i = 1;
    set<int> s;
    SmallestInfiniteSet() {
    }
    
    int popSmallest() {
        if(s.size() == 0){
            return i++;
        }
        else{
            int a = *s.begin();
            if(i > a){
                s.erase(a);
                return a;
            }
            return i++;    
        }
    }
    
    void addBack(int num) {
        if(i > num) s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */