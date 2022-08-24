
/* 

    Solution by Rahul Surana

    ***********************************************************

    Question not available due to hackerearth test questions are not viewable

   ***********************************************************
*/



#include<bits/stdc++.h>
using namespace std;

int arr[26];

void sk(string s){
   // if(s.length() < k) return false;
   int c = 0;
   int ar[26];
   memset(ar,0,sizeof(ar));
   for(int i = 0;i < s.length(); i++){
      if(ar[s[i]-'a']==0) {c++;}
      ar[s[i]-'a']++; 
   }
   for(int i = 1;i<=26;i++){ arr[i-1] += c>=i;}
}


vector<long long> DistinctChars (int N, string S) {
   vector<long long> v;
   for(int j = 0; j < S.length();j++){
      for(int k = 1; k <= S.length()-j;k++){
         string ss = S.substr(j,k);
         sk(ss);
      }
   }
   for(int i=0;i<26;i++) v.push_back(arr[i]);
   return v;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<long long> out_;
    out_ = DistinctChars(N, S);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}