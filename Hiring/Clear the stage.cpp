






/* 

    Solution by Rahul Surana

    ***********************************************************


    ======================================================

    Clear the stage - Under progress Not solved Yet

    ======================================================


    ***********************************************************

*/







#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(2,vector<int>(100001,INT_MAX));

int split_unsplit(int power, vector<int> X, vector<int> Type, int index, int no_of_split, int target){
    // cout << index<<" " <<power <<" "<< no_of_split <<" \n";
    if(Type[index] == 2) { if(power < X[index] ) return INT_MAX;
    else{ if(index == target) return no_of_split; else return split_unsplit(power,X,Type,index+1,no_of_split,target); } }
    if(Type[index] == 1) {
        return min(split_unsplit(power+X[index]-1,X,Type,index+1,no_of_split+1,target),split_unsplit(power,X,Type,index+1,no_of_split,target));
    }
}

int minimumSplits (int N, vector<int> X, vector<int> Type) {
   int c = 0;
   int m2 = -1;
   int ind2 = -1;
   int power = 1;
   for(int i= 0; i < N; i++){
       if(m2<X[i] && Type[i] == 2) { m2 = X[i]; ind2 = i; }
   }
   c = split_unsplit(power,X,Type,0,0,ind2);
//    for(int i= 0; i < N; i++){
//     //    int max_power = -1;
//        if(Type[i] == 1){
//         //    if(X[i] == m1){
//         //        while(power<m2) { power+=(X[i]-1); c++; }
//         //        break;
//         //    }
//         //    else{
//         //        int p = X[i];
//         //        int j = i;
//         //        while(j<N-1 && Type[j+1] == 1) { if(X[j+1]>p) { p = X[j+1]; } j++; }
//         //        i = j;
//         //        if(p>max_power) max_power = p;
//         //        int temp_p = -1;
//         //        if(j<N-1 && Type[j+1] == 2) { temp_p = X[j+1]; i++; }
//         //        if(temp_p != -1){
//         //            while(power < X[j+1]) { power += (max_power-1); c++; }
//         //        } 
//         //    }
//         int j = i+1;
//         int pn = 0;
//         while(j<N) { 
//             if(Type[j] == 2) { 
//                 int mpn = X[j]; 
//                 int k =1; 
//                 while( j+k < N && Type[j+k] ==2 ) {
//                     if(mpn < X[j+k]) mpn = X[j+k]; 
//                 }
//                 pn = mpn; 
//                 break;
//             }
//             j++; 
//         }
//         if(pn > power) { power+=(X[i]-1); c++; }
//        }
//        else{
//            if(power < X[i]) return -1; 
//        }
//    }
   return c;
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
        vector<int> X(N);
        for(int i_X = 0; i_X < N; i_X++)
        {
        	cin >> X[i_X];
        }
        vector<int> Type(N);
        for(int i_Type = 0; i_Type < N; i_Type++)
        {
        	cin >> Type[i_Type];
        }

        int out_;
        out_ = minimumSplits(N, X, Type);
        cout << out_;
        cout << "\n";
    }
}