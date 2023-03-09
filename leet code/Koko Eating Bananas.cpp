
/*

Solution by Rahul Surana

    ***********************************************************


Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 


    ***********************************************************


*/



#include <bits/stdc++.h>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int64_t s = 0;
        for(int k = 0; k < piles.size(); k++){
            s += piles[k];
        }
        int i = max(1,static_cast<int>(s/h)), j = (s/(h-piles.size()+1))+1; 
        
        auto x = [=](int a){
            int z = 0;
            for(int k = 0; k < piles.size(); k++){
                z+= (piles[k]/a) + (piles[k]%a != 0);
            }
            return z;
        };
        while(i!=j){
            int mid = (j + i)/2;
            int m = x(mid);
            if(m <= h) j = mid;
            else if(m > h) i = mid+1;
        }
        return i;
    }
};