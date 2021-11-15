

/* 

    Solution by Rahul Surana
    

    ***********************************************************


Design the CombinationIterator class:

CombinationIterator(string characters, int combinationLength) Initializes the object with a string 
characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
next() Returns the next combination of length combinationLength in lexicographical order.
hasNext() Returns true if and only if there exists a next combination.



    ***********************************************************
*/



#include <bits/stdc++.h>
class CombinationIterator {
public:
    
    vector<string> x;
    int j = 0;
    void comb(int i, int n, string ch, int cl,string c){
        if(i>n) return;
        // cout << c <<" ";
        if(c.length() == cl) {  x.push_back(c); return; }
        comb(i+1,n,ch,cl,c);
        comb(i+1,n,ch,cl,c+ch[i]);
    }
    
    CombinationIterator(string characters, int combinationLength) {
        comb(0,characters.length(),characters,combinationLength,"");
        // for(auto m : x){cout << m <<" \n";}
        sort(x.begin(),x.end());
    }
    
    string next() {
        if(j >= x.size()) return "";
        return x[j++];
    }
    
    bool hasNext() {
        if(j == x.size()) return false;
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */