

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, 
find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from 
node i (i.e., there is a directed edge from node i to node graph[i][j]).


    ***********************************************************
*/


class Solution {
    public int missingNumber(int[] nums) {
        int ans = 0, n = nums.length;
        for(int x: nums) ans ^= x;
        if(n%4 == 0) return (ans^n);
        if(n%4 == 1) return (ans^1);
        if(n%4 == 2) return (ans^(n+1));
        return ans;
    }
}