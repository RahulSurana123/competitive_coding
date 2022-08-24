

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two strings S1 and S2 in lowercase, the task is to make them anagram. 
The only allowed operation is to remove a character from any string. 
Find the minimum number of characters to be deleted to make both the strings anagram. 
Two strings are called anagram of each other if one of them can be converted into another by rearranging its letters.



    ***********************************************************
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2)
{
    vector<int> f(26,0);
    for(int i = 0 ; i < max(str2.length(),str1.length());i++){
        if(i<str2.length()) f[str2[i]-'a']++;
        if(i<str1.length()) f[str1[i]-'a']--;
    }
    int ans = 0;
    for(int i = 0 ; i < 26;i++){
        ans+=abs(f[i]);
    }
    return ans;
}