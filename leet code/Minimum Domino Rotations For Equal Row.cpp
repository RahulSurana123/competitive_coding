

/* 

    Solution by Rahul Surana
    
    ***********************************************************


In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. 
(A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int x = -1; 
        for(int i = 1; i <= 6; i++){
            bool f = true;
             int up = 0,down = 0;
            for(int j = 0; j < tops.size(); j++){
                if(tops[j] != i && bottoms[j] != i){
                    f = false;
                    break;
                }
                if(bottoms[j] == i && tops[j] == i){
            
                }
                else if(tops[j] == i) up++;
                else down++;
            }
            if(f){
                return min(up,down);
            }
        }
        return x;
    }
};