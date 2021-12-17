

/* 

    Solution by Rahul Surana
    

    ***********************************************************


There is a city in Wonderland in which N male and female people(in total N people) are standing in the form of a tree in a way such that the root node has a male and all following level of tree nodes are in alternate fashion, that is next level contains all females and similarly it's next level contains all males. Initially, all people have a binary value (0 or 1) which is given in input.
Now Ninja was given a task to change these binary value to the goal values(given in input) using the following operation:
- In each operation Ninja chooses some node such that it's value flips (0 to 1 or 1 to 0). And if that node is male then all the following male values gets flipped. Same for females, that if chosen node is female, along with it's value, all the following values of female nodes get flipped.
Find the minimum number of operations to change given value of nodes to the goal value of nodes.

 



    ***********************************************************
*/


#include<bits/stdc++.h>
using namespace std;


int ar[100001],t[100001];
vector<vector<int>> adj;
vector<int> changes;
int ans = 0;

void dfs(int i,int p,bool t){
    if(t) { 
        // cout << i << " ";
        if(ar[i] == 1) ar[i] = 0;
        else ar[i] = 1;
    }
    for(int j = 0; j<adj[i].size(); j++){
        if(adj[i][j] != p){
            if(t) dfs(adj[i][j],i,false);
            else dfs(adj[i][j],i,true);
        }
    }
}

void dcfs(int i, int p){
    
    if(ar[i] != t[i]) {  
        // cout << i <<" -> "<<ar[i]<<" "<<t[i]<<"\n";
        ans++;
        dfs(i,p,true); 
        // cout <<"\n";
    }
    for(int j = 0; j<adj[i].size(); j++){
        if(adj[i][j] != p){
            dcfs(adj[i][j],i);
        }
    }
}

int main(){
    
    // int s;
    // cin >>s;
    // while(s--) {
        int n;
        cin >> n;
        adj.clear();
        adj.resize(n+1,vector<int>());
        changes.clear();
        changes.resize(n,0);
        for(int i = 0; i < n-1; i++){
            int a,b;
            cin >> a>>b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 0 ; i < n; i++) cin >> ar[i];
        for(int i = 0 ; i < n; i++) cin >> t[i];
        dcfs(0,-1);
        // for(int i = 0 ; i < n;i++){
        // ans += ar[i] != t[i];
        // // ans = max(ans,changes[i]);
        // }
        cout << ans<<"\n";
    // }
    return 0;
}