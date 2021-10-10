

/* 
    Solution by Rahul Surana
    
    ***********************************************************


In this problem, we define "set" is a collection of distinct numbers. For two sets A and B, we define their sum set is a set S(A,B) = { a + b | a belongs A and b belongs B }.
In other word,  set S(A,B) contains all elements which can be represented as sum of an element in A and an element in B. Given two sets A,C, 
your task is to find set B of positive integers less than or equals 100 with maximum size such that S(A,B) = C. It is guaranteed that there is unique such set.

Input Format

The first line contains N denoting the number of elements in set A, the following line contains N space-separated integers a(i) denoting the elements of set A.

The third line contains M denoting the number of elements in set C, the following line contains M space-separated integers c(i) denoting the elements of set C.

Output Format

Print all elements of B in increasing order in a single line, separated by space.



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
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1000000007 
using namespace std;


int main()
{
    fast_io;
    int n,m;
    cin >> n;
    int ar[n];
    FOR(i,n) cin >> ar[i];
    cin >> m;
    set<int> c;
    FOR(i,m) { int x ; cin >> x; c.insert(x); }
    set<int> s;
    for(int i = 1; i <= 100;i++){
        bool f = true;
        for(int j = 0; j < n; j++){
            if(!(c.count(ar[j]+i))){
                f = false;
            }
        }
        if(f) s.insert(i);
    }
    for(int i = 1; i <= 100; i++){
        if(s.count(i)) cout << i <<" ";
    }
}