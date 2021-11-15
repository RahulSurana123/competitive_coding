



/* 

    Solution by Rahul Surana

    ***********************************************************

Given Array A and Number K

Do minimum no of operation so that below condition is satified for each i

A[i] <= A[i+K]  

Operation which can be performed -> change A[i] to any value of your choice


    ***********************************************************
*/



#include<bits/stdc++.h>
using namespace std;

int minOperations (int N, vector<int> A, int K) {

    int ans = 0;
    for(int i = 0 ; i < K; i++){
        vector<int> l;
        int c = 0,p=0;
        for(int j = i; j < N; j+=K){
            auto it = upper_bound(l.begin(), l.end(), A[j]);
            if(it == l.end()){
                l.push_back(A[j]);
            }
            else{
                *it = A[j];
            }
            c++;
        }
        ans+=c-l.size();
    }
    return ans;


//    int op = 0;
//    vector<int> ps[K][2];
//    vector<vector<int>> X(K,vector<int>());
//    for(int i = 0 ; i < N; i++){
//        X[i%K].push_back(A[i]);
    
//    }
//    for(int i = 0 ; i < K; i++){
//        int m = A[i];
//        int pso = 0;
//        for(int j = 1; j < X[i].size();j++){
//             // cout << X[i][j]<<" ";
//             if(m > X[i][j]) { pso++; m = X[i][j]; }
//             ps[i][0].push_back(pso);
//        }
//     //    cout <<"\n";
//    }
//    for(int i = N-1 ; i >= 0; i--){
//        int m = A[i];
//        int pso = 0;
//        for(int j = X[i].size()-1; j > 0;j--){
//             // cout << ps[i][0]<<" ";
//             if(m < X[i][j]) { pso++; m = X[i][j]; }
//             ps[i][1].push_back(pso);
//        }
//     //    cout <<"\n";
//    }
//    for(int i = 0 ; i < K; i++){
//        for(auto z: ps[i][0]){
//            cout << z<<" ";
//        }
//        cout <<"\n";
//        for(auto z: ps[i][1]){
//            cout << z<<" ";
//        }
//        cout <<"\n";
//    }
// //    for(int i = 0 ; i < K; i++){
// //        int j = i;
// //        while(j+K < N) { 
// //            if(A[j] > A[j+K]) { 
// //                op++; A[j] = A[j+K]; 
// //             } 
// //             j+= K;  
// //         }
// //    }
//    return op;
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
        vector<int> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
        	cin >> A[i_A];
        }
        int K;
        cin >> K;

        int out_;
        out_ = minOperations(N, A, K);
        cout << out_;
        cout << "\n";
    }
}