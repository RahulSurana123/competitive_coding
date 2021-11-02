
/* 

    Solution by Rahul Surana

    ***********************************************************

There is a Row of building. Cricket Fan Wants to watch match. 
For k(i) (no of building in front of ith less than or equal height) find out they can watch match from how many buildings  


Inputs:
-> No of Building ( N )
-> Array of Height of Building  ( A )
-> Array of Maximum Building In front of your Building  ( K )

Output:

No of Building From Which a person can Watch Cricket Match

    ***********************************************************
*/


#include <bits/stdc++.h>

#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int count_buildings (int N, int* A, int* K) {
   int c = 0;
   int ind = 0;
   int height = 0;
   for(int i = 0; i < N; i++){
       if( *(A+i) >= height ) { height = *(A+i); ind = i; } 
   }
   if(ind <= *(K+ind)) c++;
   int dp[N];
   memset(dp,-1,sizeof(dp)); 
   for(int i = 0; i < ind; i++){
       if(i == 0){
           if(*K > 0) c++;
       }
       else{
           int m = 0;
           bool f = false;
            for(int j = i-1; j>=0; j--){
                if(*(A+j) <= *(A+i)) { m++; if(dp[j] != -1) { m+=dp[j]; break; } }
                else{ f = true; break;}
            }
            if(!f) { 
                if(m <= *(K+i)) c++;
                dp[i] = m;
            }
       }
   }

   return c;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        scanf("%d", &N);
        int i_A;
        int *A = (int *)malloc(sizeof(int)*(N));
        for(i_A = 0; i_A < N; i_A++)
        	scanf("%d", &A[i_A]);
        int i_K;
        int *K = (int *)malloc(sizeof(int)*(N));
        for(i_K = 0; i_K < N; i_K++)
        	scanf("%d", &K[i_K]);

        int out_ = count_buildings(N, A, K);
        printf("%d", out_);
        printf("\n");
    }
}