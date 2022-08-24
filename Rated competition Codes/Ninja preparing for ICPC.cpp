

/* 

    Solution by Rahul Surana
    

    ***********************************************************


Ninja is a brilliant competitive programmer, and he wants to score well in the upcoming ICPC competition. 
But he is stuck in a problem and asks you for your help.

The problem is simple: you're given a rooted tree with n vertices, where vertex 1 is the root of the tree. 
You’re given an operation, and you can perform this operation any number of times. 

Your task is to minimize the number of leaves and output that number.
The operation has been described below in the next few lines.

In one operation, you can choose any joint** with all of its children and re-hang them to any other vertex of the tree. 
By doing this, you delete the edge connecting the joint and its parent and add an edge between this joint and the chosen vertex of the tree. 
Also, The chosen vertex cannot be joined to itself or any of its children

        

    ***********************************************************
*/



#include<bits/stdc++.h>
using namespace std;

int ar[200001];
vector<vector<int>> adj;
int ans = 0;

int dfs(int i, int p){
    int height = 0;
    for(int j = 0 ; j < adj[i].size(); j++){
        if(adj[i][j] != p){
            height += dfs(adj[i][j],i);
        }
    }
    if(!height) return 1;
    ans+=height-1;
    return 0;
}

int main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        ans=0;
        adj.resize(n+1,vector<int>());
        for(int i = 0; i <= n;i++) adj[i].clear();
        for(int i = 0; i < n-1; i++){
            int a,b;
            cin >> a>>b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }   
        dfs(0,-1);
        cout << ans+1 <<"\n";
    }
    
    return 0;
}