

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, 
be stored in the input character array chars. 
Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.



    ***********************************************************
*/


#include <bits/stdc++.h>

#include <stdio.h>
#include <string.h>
class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ans = 0;
        string a = string(chars.begin(),chars.end());
        chars.clear();
        // cout << a<<"\n";
        while(i < a.length()){
            string e(1,a[i]);
            // cout << f <<" "<< e <<" \n";
            int x = strspn(a.substr(i).c_str(),e.c_str());
            //  cout << x <<" "<<i<<" "<<ans <<"\n";
            if(x >= 2) { 
                ans+=1; 
                chars.push_back(a[i]);  
                string q; 
                int z = x;
                while(z>0){ 
                    q+= ((z%10)+'0'); 
                    z/=10;
                } 
                ans += q.length(); 
                for(int k = q.length()-1; k >=0 ; k--) chars.push_back(q[k]);  
            }
            else { ans++; chars.push_back(a[i]); }
           
            i += x;
            // i++;
        }
        return ans;
    }
};