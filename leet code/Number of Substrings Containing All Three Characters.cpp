
/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.



    ***********************************************************
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int a = 0, b = 0, c = 0, j = 0;
        for(int i = 0; i < s.length(); i++){
            int ch = s[i];
            if(ch=='a') a++;
            else if(ch =='b')b++;
            else c++;
            while(a > 0 && b > 0 && c > 0 && j < i){
                int cha = s[j];
                if(cha=='a') a--;
                else if(cha =='b')b--;
                else c--;
                ans += s.length()-i;
                j++;
                // cout << a << " " << b<<" " << c<<"\n";
            }
        }
        return ans;
    }
};
