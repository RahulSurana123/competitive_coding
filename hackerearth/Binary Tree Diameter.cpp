

/* 


    Solution by Rahul Surana

    ***********************************************************

Given a binary tree which has T nodes, you need to find the diameter of that binary tree. The diameter of a tree is the number of nodes on the longest path between two leaves in the tree.

Input:

First line contains two integers, T and X, number of nodes in the tree and value of the root.
Next 2 * (T - 1) lines contain details of nodes.
Each detail of node contains two lines. First lines contains a string and second line contains an integer, 
which denotes the path of the node and the value of the node respectively.

String consists of only L or R. L denotes left child and R denotes right child. ( Look at the sample explanation for more details )


Output:

Print the diameter of the binary tree.


SAMPLE INPUT 

5 1
L
2
R
3
LL
4
LR
5

SAMPLE OUTPUT 

4

    ***********************************************************

*/


#include <bits/stdc++.h>
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define FOR(i,a)     for(int i = 0; i < a; i++)
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1000000007 
using namespace std;

int ar[20*10000];

int z=-1;
int maxl(int i){
    if(ar[i]==-1) return 0;
    
    int lm = maxl(i*2) + 1;
    int rm = maxl((i*2)+1) + 1;
    if(z<lm+rm) { z = lm+rm-1; }
    return max(lm,rm);
}

int main()
{
	fast_io;
    int n,x;
    cin >> n >> x;
    mem(ar,-1);
    ar[1] = x;
    FOR(i,n-1) {
        int k;
        string s;
        cin >> s >> k;
        int ind =1;
        FOR(j,s.length()) { ind *=2; if(s[j] == 'R') ind++; }
        // cout << ind << " " <<k << "\n";
        ar[ind] = k;
    }
    maxl(1);

    cout << z;

}
