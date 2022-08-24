
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
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

using namespace std;

int main()
{
    fast_io;

    string s;
    cin >> s;
    int i = 0;
    vector<double> nums;
    vector<char> e; 
    while(i < s.length()){
        string x;
        while(i < s.length() && s[i] >= '0' && s[i] <= '9') x += s[i++];
        double z = (double)stoi(x);
        nums.push_back(z);
        while(i < s.length() && !(s[i] >= '0' && s[i] <= '9')) e.push_back(s[i++]);
    }
    stack<double> n;
    stack<char> o;

    // vector<int> eindex(expersion.size());
    // for(int j = 0 ; j < expersion.size(); j++){
    //     eindex[j] = j;
    // }
    string a = "-+*/";
    // double ans = 0;
    double last;
    for(int j = 0; j < a.length(); j++){
        for(int k = 0; k < e.size(); k++){
            if(e[k] == a[j]) { n.push(nums[k+1]); last = nums[k]; o.push(a[j]); } 
        }
    }
    n.push(last);
    while(n.size()>1){
        double l = n.top();
        n.pop();
        double m = n.top();
        n.pop();
        char f = o.top();
        o.pop();
        // cout << l <<" "<<m <<" "<< f <<"\n";
        if(f == '/') n.push((double)(m/l));
        if(f == '*') n.push((double)(m*l));
        if(f == '+') n.push((double)(m+l));
        if(f == '-') n.push((double)(m-l));
    }
    double ans = n.top();
    cout << ans;

}