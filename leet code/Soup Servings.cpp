

/* 

    Solution by Rahul Surana
    
    ***********************************************************

There are two types of soup: type A and type B. Initially, we have n ml of each type of soup. 
There are four kinds of operations:

Serve 100 ml of soup A and 0 ml of soup B,
Serve 75 ml of soup A and 25 ml of soup B,
Serve 50 ml of soup A and 50 ml of soup B, and
Serve 25 ml of soup A and 75 ml of soup B.
When we serve some soup, we give it to someone, and we no longer have it. 
Each turn, we will choose from the four operations with an equal probability 0.25. 
If the remaining volume of soup is not enough to complete the operation, we will serve as much as possible. 
We stop once we no longer have some quantity of both types of soup.

Note that we do not have an operation where all 100 ml's of soup B are used first.

Return the probability that soup A will be empty first, 
plus half the probability that A and B become empty at the same time. 
Answers within 10-5 of the actual answer will be accepted.

    ***********************************************************
*/

class Solution {
public:
    unordered_map<int,unordered_map<int,double>> dp;
    double df(int a, int b){
        // if(a<0 || b <0) return 1.0;
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1.0;
        if(b<=0) return 0.0;
        if(dp[a].count(b)) return dp[a][b];
        // cout << a<<" "<<b <<"\n";
        return dp[a][b] = (df(a-4,b) + df(a-3,b-1)+df(a-2,b-2)+df(a-1,b-3))/4; 
    }

    double soupServings(int n) {
        if(n>4800) return 1;
        int m = ceil(n/25.0);
        for(int i = 1; i<= m; i++){
            if(df(i,i) > 1-(1e-5)){
                return 1;
            }
        }
        return df(m,m);
    }
};