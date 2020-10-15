

/* 

    Solution by Rahul Surana

    ***********************************************************

Alice has a rectangular matrix of size 10^18 x 10^18. We assume that the matrix rows are numbered from 1 to 10^18 from top to bottom, and the matrix columns are numbered from 1 to 10^18 from left to right. Then the cell of the field at the intersection of the x-th row and the y-th column has coordinates (x.y).

Once Alice had tortoises in this matrix, but now he gets bored from tortoises because they are very slow and this large matrix is definitely not for them. So he decides to replace it with rabbits. Initially, rabbits stand at cell (1, 1). One of the hallmarks of rabbits is that they are very fast. They are twice faster than tortoises and can get from a cell (x, y) into a cell (2 ∗ x, y) or (x, 2 ∗ y) in a few seconds. Also they can go to (x, y − x) or (x − y, y). But the rabbits can not go out of the bounds of the matrix.

It turns out that rabbits got hungry very quickly (this is due to a very fast digestive system). So Alice buys food for them for the next q days and puts this food to cell (xi , yi) in the i-th day. But he does not know are these cells reachable. And he asks you to help him. For each day determine can Alice's rabbits be happy or not.

Input format:

The first line contains single integer q (1 ≤ q ≤ 3 ∗ 10^5 ) - number of days.
The next q lines contains two space-separated integers xi and yi (1 ≤ xi , yi ≤ 10^18) - the coordinates of food.
Output format:

Output : 

For each of q days print on a single line "Yes if there is a way from cell (1; 1) to cell (xi , yi), that meets the requirements, and "No"otherwise.

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
 
using namespace std;

int inf=1e9+7,MOD=1e9+7;
// const int l = 1e9;

ll int gcd(ll int x,ll int y){
    
    if (y==0) return x;
    return gcd(y,x%y);
}


int main()
{
	fast_io;
    int t;
    cin >> t;
    // vi qd = da();
    while(t--){
        ll int a,b;
        cin >> a >> b;
        ll int ans = gcd(a,b); 
        if((ans & (ans-1))) cout<<"No\n";
        else  cout<<"Yes\n";

        
    }
    

}