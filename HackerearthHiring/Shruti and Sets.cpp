


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Shruti and Sets

Shruti and Manas are playing with numbers. Manas gave N distinct positive numbers to Shruti. Shruti will insert all these N elements to a set S.

(Recall that a set is a collection of distinct objects, so   |S|   will not change if you attempt to insert a value it already contains) .

Now, Manas asks Shruti to tell her the K<sup>th</sup> greatest element present in the set after performing the following task.
	
	Shruti has to choose all pairs of two numbers from the set and find their absolute difference and insert this difference back into the set.
	
	
	Shruti has to perform the above operation on S until |S| no longer changes.
	
Can you help Shruti ?

Input Format:

	First line contains N i.e number of distinct elements
	Next line contains N distinct elements.
	Last line contains K.


Output Format:

Output the K(th) largest element after performing the above operations.




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
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;
int inf=1e9+7, MOD=1e9+7;


int main()
{
    set<int> s;
    vector<int> prev;
    vector<int> next;
	fast_io;
    int n;
    cin >>n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        next.pb(x);
        s.insert(x);
    }
    for(int i = 0; i < next.size(); i++){
        for (int j = i+1; j < next.size(); j++){
        if(!s.count(abs(next[i] - next[j]))){
            s.insert(abs(next[i] - next[j]));
            prev.pb(abs(next[i] - next[j]));    
        }}
    }
    vector<int> newer;
    while(prev.size() != 0){
        for(int i = 0; i < next.size(); i++){
            for(int j = 0 ; j < prev.size(); j++){
                if(!s.count(abs(prev[j] - next[i]))){
                    s.insert(abs(prev[j] - next[i]));
                    newer.pb(abs(prev[j] - next[i]));
                    next.pb(abs(prev[j] - next[i]));
                }
            }
        }

        if(newer.size() <= 1) break;
        prev.clear();
        for(int i =0; i< newer.size();i++){
            prev.pb(newer[i]);
        }

    }
    vector<int> finaldata(s.begin(),s.end());
    sort(finaldata.begin(),finaldata.end(),greater<int>());
    int k;
    cin >> k;
    // for(int i = 0; i < finaldata.size();i++){
    //     cout << finaldata[i] <<" ";
    // }
    cout << finaldata[k-1] <<"\n";
}