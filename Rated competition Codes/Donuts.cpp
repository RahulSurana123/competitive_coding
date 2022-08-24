

/* 

    Solution by Rahul Surana
    

    ***********************************************************

Code Ninja Code Kaze competition


Ninja loves eating donuts. He consumes 4 donuts per day. When he eats 4 donuts such that their weight is w1 ≤ w2 ≤ w3 ≤ w4 , he gains weight w2 (second minimum value in the group).
You are given an array that contains the weight of n donuts. Your task is to determine the maximum total weight Ninja can gain by eating the donuts optimally each day.
Note: n is always a multiple of 4



    ***********************************************************
*/



#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ar[n];
        for(int i = 0 ; i < n ; i++){
            cin>>ar[i];
        }
        sort(ar,ar+n);
        int ans=0;
        for(int i = 0; i < n/4;i++){
            ans+= ar[n-(3*(i+1))];
        }
        cout << ans<<"\n";
    }
    return 0;
}