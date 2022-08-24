

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A Bitset is a data structure that compactly stores bits.

Implement the Bitset class:

Bitset(int size) Initializes the Bitset with size bits, all of which are 0.
void fix(int idx) Updates the value of the bit at the index idx to 1. If the value was already 1, no change occurs.
void unfix(int idx) Updates the value of the bit at the index idx to 0. If the value was already 0, no change occurs.
void flip() Flips the values of each bit in the Bitset. In other words, all bits with value 0 will now have value 1 and vice versa.
boolean all() Checks if the value of each bit in the Bitset is 1. Returns true if it satisfies the condition, false otherwise.
boolean one() Checks if there is at least one bit in the Bitset with value 1. Returns true if it satisfies the condition, false otherwise.
int count() Returns the total number of bits in the Bitset which have value 1.
String toString() Returns the current composition of the Bitset. 
Note that in the resultant string, the character at the ith index should coincide with the value at the ith bit of the Bitset.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Bitset {
public:
    vector<char> b;
    bool f;
    int x;
    Bitset(int size) {
        this->b.resize(size,'0');
        this->x = 0;
        this->f = false;
    }
    
    void fix(int idx) {
        if((this->b[idx] == '0' && !this->f) || (this->b[idx] == '1' && this->f)) this->x += 1; 
        if(!this->f) this->b[idx] = '1';
        else this->b[idx] = '0';
        cout << this->x <<" ";
    }
    
    void unfix(int idx) {
        
        if((this->b[idx] == '1' && !this->f) || (this->b[idx] == '0' && this->f)) this->x -= 1; 
        if(!this->f) { this->b[idx] = '0'; }
        else { this->b[idx] = '1'; }
        cout << this->x <<" \n";
    }
    
    void flip() {
        this->f = this->f ? false:true;
        this->x = this->b.size()-this->x;
        cout << this->x <<" ";
    }
    
    bool all() {
        if(this->x == this->b.size()) return true;
        return false;
    }
    
    bool one() {
        if(this->x >= 1) return true;
        return false;
    }
    
    int count() {
        // int ans = 0;
        // for(int i = 0 ; i < this->b.size(); i++) {
        //     if(this->b[i] == 1) ans++;
        //     // else b[i] = 1;
        // }
        return this->x;
    }
    
    string toString() {
        string ans;
        for(int i = 0 ; i < this->b.size(); i++) {
            if((this->b[i] == '1' && !this->f) || (this->b[i] == '0' && this->f)) ans+='1';
            else ans+='0';
            // else b[i] = 1;
        }
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */