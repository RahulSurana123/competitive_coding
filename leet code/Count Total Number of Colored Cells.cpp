/* 
    Solution by Rahul Surana
    
    ***********************************************************


There exists an infinitely large two-dimensional grid of uncolored unit cells. 
You are given a positive integer n, indicating that you must do the following routine for n minutes:

At the first minute, color any arbitrary unit cell blue.
Every minute thereafter, color blue every uncolored cell that touches a blue cell.
Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3.



    ***********************************************************
*/

class Solution {
public:
    long long coloredCells(int n) {
        int h = 1;
        long long ans = 1;
        for(int i = 0; i < n-1; i++){
            ans += 2*h + 2;
            h+=2;
        }
        return ans;
    }
};
