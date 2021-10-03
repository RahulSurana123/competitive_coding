
/* 
    Solution by Rahul Surana
    
    ***********************************************************

Every valid email consists of a local name and a domain name, separated by the '@' sign. Besides lowercase letters, the email may contain one or more '.' or '+'.

For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.
If you add periods '.' between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name. Note that this rule does not apply to domain names.

For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.
If you add a plus '+' in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered. Note that this rule does not apply to domain names.

For example, "m.y+name@email.com" will be forwarded to "my@email.com".
It is possible to use both of these rules at the same time.

Given an array of strings emails where we send one email to each email[i], return the number of different addresses that actually receive mails.



    ***********************************************************
*/


class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        int unique = 0;
        set<string> s;
        for(auto x: emails){
            string front = "";
            string back  = "";
            bool fa = true,fp = false;
            for(int i = 0; i < x.length();i++){
                if(x[i] == '@'){
                    fa = false;
                }
                if(x[i] == '+' ){
                    fp = true;
                }
                if(!fp && x[i] != '.' && fa){
                    front += x[i];
                }
                if(!fa){
                    back += x[i];
                }
            }
            if(!s.count(front+back)){
                unique += 1;
                s.insert(front+back);
            }
        }
        for(auto x: s){
            cout << x <<"\n";
        }
        return unique;
    }
};