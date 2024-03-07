

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each tokens[i] donates the value of tokeni.

Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):

Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
Return the maximum possible score you can achieve after playing any number of tokens.


    ***********************************************************
*/

class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);
        int ans = 0, fa = 0, i = 0, j = tokens.length-1;
        while(j>=i){
            if(power >= tokens[i]) { ans += 1; power-=tokens[i++]; fa = Math.max(fa,ans); }
            else if(ans >= 1) { ans-=1; power += tokens[j--]; }
            else return fa;  
        }
        return fa;
    }
}