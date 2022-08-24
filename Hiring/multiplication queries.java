import java.io.*;
import java.util.*;


public class TestClass {

    static int[] p;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine().trim());
        for(int t_i = 0; t_i < T; t_i++)
        {
            int N = Integer.parseInt(br.readLine().trim());
            int[][] edges = new int[N-1][2];
            for(int i_edges = 0; i_edges < N-1; i_edges++)
            {
            	String[] arr_edges = br.readLine().split(" ");
            	for(int j_edges = 0; j_edges < arr_edges.length; j_edges++)
            	{
            		edges[i_edges][j_edges] = Integer.parseInt(arr_edges[j_edges]);
            	}
            }
            String[] arr_A = br.readLine().split(" ");
            int[] A = new int[N];
            for(int i_A = 0; i_A < arr_A.length; i_A++)
            {
            	A[i_A] = Integer.parseInt(arr_A[i_A]);
            }
            int Q = Integer.parseInt(br.readLine().trim());
            int[][] queries = new int[Q][3];
            for(int i_queries = 0; i_queries < Q; i_queries++)
            {
            	String[] arr_queries = br.readLine().split(" ");
            	for(int j_queries = 0; j_queries < arr_queries.length; j_queries++)
            	{
            		queries[i_queries][j_queries] = Integer.parseInt(arr_queries[j_queries]);
            	}
            }

            int[] out_ = multiplication_queries(N, edges, A, Q, queries);
            System.out.print(out_[0]);
            for(int i_out_ = 1; i_out_ < out_.length; i_out_++)
            {
            	System.out.print(" " + out_[i_out_]);
            }
            
            System.out.println();
            
         }

         wr.close();
         br.close();
    }

    static void dfs(int x, int[] A, int k, LinkedList<Integer>[] adj){
        A[x-1] = (A[x-1] % 998244353 * k % 998244353)% 998244353;
        for(int i = 0; i < adj[x].size();i++){
            dfs(adj[x].get(i),A,k,adj);
        }
    }

    static int lca(int s, int x, int y,boolean xt,boolean yt,int[] A,  LinkedList<Integer>[] adj){
        boolean[] v = new boolean[100001];
        while(v[x]==false) { v[x] = true; x = p[x]; }
        while(v[y] == false) { y = p[y]; }
        return A[y-1];
    }

    static int[] multiplication_queries(int N, int[][] edges, int[] A, int Q, int[][] queries){
        p = new int[N+1];
       LinkedList<Integer> adj[] = new LinkedList[N+1];
       for(int i = 0 ; i < N+1; i++) adj[i]=new LinkedList<>();
       for(int i = 0 ; i < edges.length; i++){
           adj[edges[i][0]].add(edges[i][1]);
           p[edges[i][1]] = edges[i][0];
       }
       ArrayList<Integer> ans = new ArrayList<>();
       for(int i = 0; i < Q; i++){
           int x = queries[i][0];
           if(x == 1){
               dfs(queries[i][1],A,queries[i][2],adj);
           }
           else if(x == 2){
               boolean a = false;
               boolean b = false;
               ans.add(lca(1,queries[i][1],queries[i][2],a,b,A,adj));
           }
       }
        int[] result = new int[ans.size()];
        for(int i = 0 ; i < ans.size();i++) result[i]= ans.get(i);

        return result;
    
    }
}