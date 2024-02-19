

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

    List<List<Integer>> ans;

    void df(int[][] graph, int i, int d, ArrayList<Integer> a){
        if(i == d){=
            ans.add(new ArrayList<>(a));
            return;
        }
        for(int x: graph[i]){
            a.add(x);
            df(graph,x,d,a);
            a.remove(a.size()-1);
        }
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        ans = new ArrayList<>();
        ArrayList<Integer> a = new ArrayList<>();
        a.add(0);
        df(graph,0,graph.length-1,a);
        return ans;
    }
}