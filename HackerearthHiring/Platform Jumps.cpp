


/* 
    Solution by Rahul Surana
    
    ***********************************************************


        Question not Available as full Screen Test


    ***********************************************************

*/



#include<bits/stdc++.h>
using namespace std;

vector<int> A;

bool compare(int a, int b){
    return A[a]>A[b];
}

vector<int> Min_Jumps (int N) {
   int index = 0;
    vector<int> ans(N,0);

    vector<int> heights(N,0);
   for( int i = 0; i < N; i++){
       heights[i] = i;
   }
   sort(heights.begin(),heights.end(),compare);
//    for( int i = 0; i < N; i++){
//        cout << heights[i]<<" ";
//    }
    ans[heights[0]] = 0;
    // int right = heights[0];
    // int left = heights[0];
    // int rc = 1, lc = 1, rm = 0, lm = 0; 
    // for(int i = 1; i < N; i++){
    //     if(heights[i] > right) { 
    //         while(right != heights[i] && right < N) { 
    //             right++; 
    //             if(right < N) ans[right] = rc; 
    //         } 
    //         rc++; 
    //     }
    //     if(heights[i] < left) { 
    //         while(left != heights[i] && left >= 0) { 
    //             left--;
    //             if(left >= 0) ans[left] = lc; 
    //         } 
    //         lc++; 
    //     }
    // }
    for( int i = 1; i < N; i++){
        int k = 1;
        while(heights[i] + k < N && A[heights[i] + k] < A[heights[i]]) k++;
        int j = 1;
        while(heights[i] - j > -1 && A[heights[i] - j] < A[heights[i]]) j++;

        if(heights[i] - j == -1) ans[heights[i]] = ans[heights[i] + k] + 1;
        else if(heights[i] + k == N) ans[heights[i]] = ans[heights[i] - j] + 1;
        else { ans[heights[i]] = min(ans[heights[i] + k] + 1,ans[heights[i] - j] + 1);  }
        // cout << heights[i] <<" " <<heights[i] + k<<" "<< heights[i] - j << "\n";
    //     if(heights[i]+1 == N || (ans[heights[i]+1] == 0 && (heights[i]+1 != heights[0]))) ans[heights[i]] = ans[heights[i]-1]+1;
    //     else if(heights[i]-1 < 0 || (ans[heights[i]-1] == 0 && (heights[i]-1 != heights[0]))) ans[heights[i]] =  ans[heights[i]+1]+1; 
    //    else ans[heights[i]] = min(ans[heights[i]+1]+1,ans[heights[i]-1]+1);
   }
//    for( int i = 1; i < N; i++){
//        if(A[index] < A[i]) index = i;
//    }
//     ans[index] = 0;
//     int mf = A[index];
//     int count = 0;
//     for(int i = index+1; i < N; i++){
//         if(A[i] > mf) { count = 1; mf = A[i]; }
//         else { count++; mf = A[i]; }
//         ans[i] = count;
//     }
//     count = 0;
//     for(int i = index-1; i >= 0; i--){
//         if(A[i] > mf) { count = 1; mf = A[i]; }
//         else { count++; mf = A[i]; }
//         ans[i] = count;
//     }
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
        A.resize(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
        	cin >> A[i_A];
        }

        vector<int> out_;
        out_ = Min_Jumps(N);
        cout << out_[0];
        for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        {
        	cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
}