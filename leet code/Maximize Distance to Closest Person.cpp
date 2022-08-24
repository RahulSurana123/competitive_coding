

/*

Solution by Rahul Surana

    ***********************************************************


You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.



    ***********************************************************


*/




#include <bits/stdc++.h>

class Solution {
public:
    int maxDistToClosest(vector<int>& s) {
        vector<vector<int>> ps(2,vector<int>(s.size(),0));
        int x = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == 1) x = 0;
            else x++;
            ps[0][i] = x;
        }
        x = 0;
        for(int i = s.size()-1 ; i >= 0; i--){
            if(s[i] == 1) x=0;
            else x++;
            ps[1][i] = x;
        }
        int f = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != 1){
                // cout << ps[0][i] <<" " << ps[1][i] <<"\n";
                if(i == 0){
                    if(f < ps[1][i]){
                        f = ps[1][i];
                        // z = i;
                    }    
                }
                else if(i == s.size()-1){
                    if(f < ps[0][i]){
                        f = ps[0][i];
                        // z = i;
                    }
                }
                else {
                    if(f < min(ps[0][i],ps[1][i])){
                        f = min(ps[0][i],ps[1][i]);
                        // z = i;
                    }
                }
                
            }
        }
        // cout << z <<"\n";
        return f;
    }
};