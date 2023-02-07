

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are visiting a farm that has a single row of fruit trees arranged from left to right. 
The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. 
There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. 
The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 



    ***********************************************************
*/



#include <bits/stdc++.h>


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> um;
        int k = 2,ans = 0,i=0;
        for(int j = 0;j < fruits.size(); j++){
            if(!um[fruits[j]]++) k--;
            while(k < 0){
                if(!--um[fruits[i]]) k++;
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};