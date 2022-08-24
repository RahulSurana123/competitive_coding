

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You have a long flowerbed in which some of the plots are planted, and some are not. 
However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, 
and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.



    ***********************************************************
*/



#include<bits/stdc++.h>

class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int x = 0;
        if(f.size()== 1){
            if(f[0] == 1 && n >= 1) return false;
            if(f[0] == 0 && n >= 2) return false;
            return true;
        }
        for(int i = 0; i < f.size(); i++){
            if(i==0){
                if(f[i+1] == 0 && f[i] == 0) {
                    x++;
                    f[i] = 1;                         
                }
            }
            else if(i==f.size()-1){
                if(f[i] == 0 && f[i-1] == 0) {
                    x++;
                    f[i] = 1; 
                }
            }
            else{
                if(f[i] == 0 && f[i-1] == 0 && f[i+1] == 0) {
                    x++;
                   f[i] = 1;
                }
            }
        }
        return x >= n;
    }
};