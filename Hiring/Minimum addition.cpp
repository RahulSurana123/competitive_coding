
/* 

    Solution by Rahul Surana

    ***********************************************************

Given N make 2 numbers from all digits of N either in number 1 or number 2 and there sum should be minimum


    ***********************************************************
*/

#include<bits/stdc++.h>
using namespace std;

int nums[10];

long long solve (long long N) {
   long long k = N;
   int count = 0;
   while(k>0){
       int x = k%10;
       nums[x]++;
       k/=10;
       count++;
   }
   long long x=0,y=0;
   bool xf = true; 
   for(int i = 0;i<10;i++){
       if(nums[i] == 0) continue;
       while(nums[i]>0){
           if(xf){
                x=((x*10)+i);
                nums[i]--;
                xf = false;
           }
           if(nums[i] == 0) break;
           if(!xf){
                y = ((y*10)+i);
                nums[i]--;
                xf = true;
           }
       }
   }
   return x+y;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        long long N;
        cin >> N;

        long long out_;
        out_ = solve(N);
        cout << out_;
        cout << "\n";
    }
}