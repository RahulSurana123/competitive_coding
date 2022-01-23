



/* 

    Solution by Rahul Surana
    
    ***********************************************************

You are Given a Array of Heights you have return a array of sum of heights such that for each i  

after subtracting i th Height you must get maximum sum of height from [L,R] where you can choose the Lth index


Note: for each ith Index you will have to remove Rth Height only and 
choose L in such way that you get max Sum of Height from [L,R-1].


Got 50% testcase passed but TLE for other 50% 


    ***********************************************************
*/




#include<bits/stdc++.h>
using namespace std;
 
vector<long long> solve (int N, vector<int> H) {
   vector<long long> ans(N);
   vector<bool> fs(N,false);
   vector<long long> mins(N), sum(N);
   mins[0] = H[0];
   sum[0] = H[0];
   for(int i = 1; i < N; i++){
       mins[i] = min((long long)H[i],mins[i-1]);
       sum[i] = sum[i-1] + H[i];
    //    cout << mins[i]<<" ";
   }
//    cout <<"\n";
   for(int i = 0 ; i < N; i++){
    //    if(mins[i] == (long long)H[i]) { 
           if(i>0) {
               bool f = false;
               long long msf = INT_MIN, meh = 0;
               for(int k = i-1; k>=0; k--){
                   if(H[k] < H[i]) break;
                //    if(ans[k] > 0 && !fs[k]) { 
                //        int x = 0;
                //        for(int m = k; m < i; m++) { x += H[m]; } 
                //        ans[i] = max(ans[k] + x,msf);
                //        fs[i] = true;
                //     //    cout << ans[k] <<" "<< x <<"\n";
                //        f = true;
                //        break;
                //     }
                   meh += H[k];
                   if(msf < meh) msf = meh;
                //    else break;
                //    if(meh < 0) meh = 0;
                   
                    // cout << msf <<" "<<meh <<" "<< H[k] <<"\n";
               }
            //    cout << "\n";
               if(!f)
               ans[i] = msf < 0 ? 0: msf;
            } 
            else ans[i] = 0; 
        // }
    //    else {
    //        int j = i;
    //        while(j >= 0 && H[i] <= H[j] ) j--;
    //        if(j == -1) ans[i] = sum[i] - H[i];
    //        else ans[i] = sum[i] - sum[j] - H[i];
           
    //     }
        if(ans[i] < 0) ans[i] = 0;
        // cout << i <<" " << sum[i-1] <<" "<< H[i]<<"\n";
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
        vector<int> H(N);
        for(int i_H = 0; i_H < N; i_H++)
        {
        	cin >> H[i_H];
        }
 
        vector<long long> out_;
        out_ = solve(N, H);
        cout << out_[0];
        for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        {
        	cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
}