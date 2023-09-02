

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. 
The string represents your movement on a number line starting from the origin 0.

In the ith move, you can choose one of the following directions:

move to the left if moves[i] = 'L' or moves[i] = '_'
move to the right if moves[i] = 'R' or moves[i] = '_'
Return the distance from the origin of the furthest point you can get to after n moves.


    ***********************************************************
*/


class Solution {
public:

    int furthestDistanceFromOrigin(string moves) {
        int x = 0, ans = 0;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i] == 'L') x++;
            else if(moves[i] == 'R') x--;
            else ans++;
        }
        return ans+abs(x);
    }
};