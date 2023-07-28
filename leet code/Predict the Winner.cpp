

/* 

    Solution by Rahul Surana
    
    ***********************************************************

You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. 
At each turn, the player takes one of the numbers from either end of the array 
(i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. 
The player adds the chosen number to their score. 
The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal,
then player 1 is still the winner, and you should also return true. 
You may assume that both players are playing optimally.

    ***********************************************************
*/

class Solution {
public:

    bool df(vector<int>& nums, int i, int j, int ps1, int ps2, bool p1c){
        if(j < i) return (ps1 >= ps2);
        if(p1c){
            return (df(nums,i+1,j,ps1+nums[i],ps2,!p1c) || df(nums,i,j-1,ps1+nums[j],ps2,!p1c));
        }
        else{
            return (df(nums,i+1,j,ps1,nums[i]+ps2,!p1c) && df(nums,i,j-1,ps1,nums[j]+ps2,!p1c));
        }
    }

    bool PredictTheWinner(vector<int>& nums) {
        return df(nums,0,nums.size()-1,0,0,true);
    }
};