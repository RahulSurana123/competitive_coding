


/* 

    Solution by Rahul Surana

    ***********************************************************

You are given two strings word1 and word2. You want to construct a string merge in the following way: while either word1 or word2 are non-empty, choose one of the following options:

If word1 is non-empty, append the first character in word1 to merge and delete it from word1.
For example, if word1 = "abc" and merge = "dv", then after choosing this operation, word1 = "bc" and merge = "dva".
If word2 is non-empty, append the first character in word2 to merge and delete it from word2.
For example, if word2 = "abc" and merge = "", then after choosing this operation, word2 = "bc" and merge = "a".
Return the lexicographically largest merge you can construct.

A string a is lexicographically larger than a string b (of the same length) if in the first position where a and b differ, a has a character strictly larger than the corresponding character in b. For example, "abcd" is lexicographically larger than "abcc" because the first position they differ is at the fourth character, and d is greater than c.



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


string largestMerge(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        int i =0, j=0,k=0;
        string s = "";
        while(i<n1+n2){
            if(j<n1&&k<n2){
                if(word1[j] > word2[k]){
                    s += word1[j++];
                    i++;
                }
                else if(word2[k]>word1[j]){
                    s+= word2[k++];
                    i++;
                }
                else{
                    char c = word1[j];
                    int sc_count = 0;
                    while(word1[j+sc_count] == c && word2[k+sc_count] == c){
                        if(j+sc_count == n1 || k+sc_count == n2) break;
                        sc_count++;
                    }
                    bool choose = false;
                    int sc_next= sc_count;
                    while(true){
                        if(j+sc_next > n1-1) { choose = false; break; }
                        else if(k+sc_next > n2-1) { choose = true; break; }
                        else if(word1[j+sc_next] > word2[k+sc_next]) { choose = true; break; }
                        else if(word1[j+sc_next] < word2[k+sc_next]) { choose = false; break; }
                        sc_next++;
                    }
                    if(choose) j+=sc_count;
                    else k+= sc_count;
                    for(int f = 0; f < sc_count;f++){
                        s+=c;
                        i++;
                    }
                }
            }
            if(j==n1){
                while(k<n2){s+=word2[k++]; i++;}
            }
            if(k==n2){
                while(j<n1){s+=word1[j++]; i++;}
            }
        }
        return s;
    }

int main()
{
    fast_io;
    
    string a,b;
    cin >> a >> b;
    cout << largestMerge(a,b)<<"\n";

}