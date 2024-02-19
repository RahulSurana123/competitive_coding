

/* 
    Solution by Rahul Surana
    
    ***********************************************************


In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. 
The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. 
The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that 
there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. 
If there are multiple answers, return the answer that occurs last in the input.


    ***********************************************************
*/


class Solution {

    int fp(ArrayList<Integer> p, int x){
        if(p.get(x) == x) return x;
        return fp(p,p.set(x,p.get(x)));
    }

    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        ArrayList<Integer> p = new ArrayList<>();
        for(int i = 0; i <= n; i++) p.add(i);
        for(int[] x: edges){
            int a = fp(p,x[0]);
            int b = fp(p,x[1]);
            if(a == b) return x;
            p.set(a,b);
        }
        return new int[0];
    }
}