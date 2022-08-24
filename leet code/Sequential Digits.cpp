
/* 

    Solution by Rahul Surana
    
    ***********************************************************


An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int l = to_string((low)).length(),h = to_string((high)).length();
        for(int i = l;i <= h; i++){
            int x = 1;
            while(true){
                long z = x;
                int j = 1;
                while(j < i) { z*=10; z+= x+j; j++; }
                if(z >= low && z <= high){
                    ans.push_back(z);
                }
                else if(z > high) break;
                x++;
                if(x>9-i+1) break;
            }
        }
        return ans;
    }
};