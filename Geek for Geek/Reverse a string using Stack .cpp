

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given a string S, the task is to reverse the string using stack.



    ***********************************************************
*/


// { Driver Code Starts

#include<bits/stdc++.h>

using namespace std;

char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}

// } Driver Code Ends


//return the address of the string
char* reverse(char *S, int len)
{
    // char* z = S;
    for(int i = 0 ; i < len/2; i++){
        char t = *(S+i);
        *(S+i) = *(S+len-i-1);
        *(S+len-i-1) = t;
        // cout << *(S+i);
    }
    return S;
}