

/* 

    Solution by Rahul Surana
    
    ***********************************************************

    Question Not available 50% test cases passing


    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;
 
long long solve (int N, int M, vector<vector<int> > matrix) {
   for(int i = 0 ; i < N; i++){
       sort(matrix[i].begin(),matrix[i].end());
   } 
   long long ans = 0;
   for(int i = 0 ; i < N; i++){
       int mans = 0;
       for(int k = 0; k < M; k++){
           int d = 0;
            int x = matrix[i][k];
            for(int j = 0; j< N; j++){
                int z = 1;
                while(z <= M && matrix[j][M-z] > x) z++;
                if(z == M+1) d+= x;
                else d+= x- matrix[j][M-z];
            }
            mans = max(mans,d);
        }
        ans += mans;
    //    cout << ans <<" ";
   }
   return ans;
}
 
int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int M;
        cin >> M;
        vector<vector<int> > matrix(N, vector<int>(M));
        for (int i_matrix = 0; i_matrix < N; i_matrix++)
        {
        	for(int j_matrix = 0; j_matrix < M; j_matrix++)
        	{
        		cin >> matrix[i_matrix][j_matrix];
        	}
        }
 
        long long out_;
        out_ = solve(N, M, matrix);
        cout << out_;
        cout << "\n";
    }
}