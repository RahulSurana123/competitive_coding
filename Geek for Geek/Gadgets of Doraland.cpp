

/* 
    Solution by Rahul Surana
    
    ***********************************************************


In Doraland, people have unique Identity Numbers called D-id. Doraemon owns the most popular gadget shop in Doraland. 
Since his gadgets are in high demand and he has only K gadgets left he has decided to sell his gadgets to his most frequent customers only. 
N customers visit his shop and D-id of each customer is given in an array array[ ]. 
In case two or more people have visited his shop the same number of time he gives priority to the customer with higher D-id. 
Find the D-ids of people he sells his K gadgets to.



    ***********************************************************
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    vector<int> TopK(vector<int>& arr, int k)
    {
        map<int,int> f;
        for(auto x: arr) f[x]++;
        vector<pair<int,int>> v;
        for(auto x:f){
            v.push_back(x);
        }
        auto fun = [&](auto a, auto b){ 
            // cout << a.first <<" ";
            if(a.second == b.second) return a.first>b.first; 
            return a.second > b.second; 
        };
        sort(v.begin(),v.end(),fun);
        vector<int> ans;
        for(auto x:v){
            if(k == 0) break;
            ans.push_back(x.first);
            k--;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}  // } Driver Code Ends