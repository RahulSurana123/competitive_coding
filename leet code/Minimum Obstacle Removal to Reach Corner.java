

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:

0 represents an empty cell,
1 represents an obstacle that may be removed.
You can move up, down, left, or right from and to an empty cell.

Return the minimum number of obstacles to remove so 
you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).


    ***********************************************************
*/


class Solution {

    int compare(int[] a, int[] b){
        if(a[0] == b[0]){
            if(a[1] == b[1]) return b[2]-a[2];
            return b[1] - a[1];
        }
        return a[0]-b[0];
    }

    public int minimumObstacles(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        boolean[][] vis = new boolean[n][m];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->compare(a,b));
        pq.add(new int[]{0,0,0});
        while(!pq.isEmpty()){
            int[] v = pq.poll();
            if(v[1] == n-1 && v[2] == m-1) return v[0];    
            if(v[1] < n-1 && !vis[v[1]+1][v[2]]){
                pq.add(new int[]{v[0]+grid[v[1]+1][v[2]], v[1]+1,v[2]});
                vis[v[1]+1][v[2]] = true;
            }
            if(v[1] > 0 && !vis[v[1]-1][v[2]]){
                pq.add(new int[]{v[0]+grid[v[1]-1][v[2]], v[1]-1,v[2]});
                vis[v[1]-1][v[2]] = true;
            }
            if(v[2] < m-1 && !vis[v[1]][v[2]+1]){
                pq.add(new int[]{v[0]+grid[v[1]][v[2]+1], v[1],v[2]+1});
                vis[v[1]][v[2]+1] = true;
            }
            if(v[2] > 0 && !vis[v[1]][v[2]-1]){
                pq.add(new int[]{v[0]+grid[v[1]][v[2]-1], v[1],v[2]-1});
                vis[v[1]][v[2]-1] = true;
            }
        }
        return -1;
    }
}