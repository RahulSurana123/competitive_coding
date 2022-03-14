

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a string path, which is an absolute path (starting with a slash '/') to a file or 
directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' 
refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. 
For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target 
file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        int i = 0;
        vector<string> a; 
        while(i < path.length()){
            string x;
            while(i < path.length() && path[i] != '/' ){
                x+=path[i++];
            }
            // cout << x <<" ";
            if(x == "..") { 
                if(a.size()>0) a.pop_back(); 
            }
            else if(x.length() && x!=".") a.push_back(x);
            
            if(i < path.length() && path[i] == '/') i++;
        }
        for(int i = 0 ; i < a.size(); i++){
            // cout << '/'+a[i] <<" ";
            ans = ans + "/" + a[i];
        }
        if(ans.length() == 0) ans+='/';
        return ans;
    }
};