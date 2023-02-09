

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of strings ideas that represents a list of names to be used in the process of naming a company. 
The process of naming a company is as follows:

Choose 2 distinct names from ideas, call them ideaA and ideaB.
Swap the first letters of ideaA and ideaB with each other.
If both of the new names are not found in the original ideas, 
then the name ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is a valid company name.
Otherwise, it is not a valid name.
Return the number of distinct valid names for the company.


    ***********************************************************
*/



#include <bits/stdc++.h>


class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        // extra idea i had
        // unordered_map<char,int> umc;
        // unordered_map<string,int> ums; 
        // unordered_map<char,set<string>> umcs;
       
        unordered_map<string,int> umsc;
       
        for(int i = 0; i < ideas.size(); i++){
            // extra idea i had
            // umc[ideas[i][0]]++;
            // ums[ideas[i].substr(1)]++;
            //  umcs[ideas[i][0]].insert(ideas[i].substr(1));
            // cout << ideas[i][0] <<" "<< umc[ideas[i][0]] <<" "<< ideas[i].substr(1)<<" "<<ums[ideas[i].substr(1)]<<"\n";
            // for(int j = i+1; j < ideas.size(); j++){
            //     if(ideas[i][0] == ideas[j][0]) continue;
            //     if(is.count(ideas[i][0]+ideas[j].substr(1)) || is.count(ideas[j][0]+ideas[i].substr(1))) continue;
            //     // cout << ideas[i] <<" "<< ideas[j]<<" \n";
            //     ans+=2;
            // }

            umsc[ideas[i].substr(1)] |= (1 << (ideas[i][0]-'a'));
               
        }
          // extra idea i had
        // for(auto x: umc){ ans -= (x.second) * (x.second-1); }
        // for(auto x: ums){ ans -= (x.second) * (x.second-1); }
        vector<vector<vector<int>>> ccb(2,vector<vector<int>>(26,vector<int>(26,0)));
        for(auto [k,ma]: umsc){ 
            for(int i = 0; i < 26; i++){
                for(int j = i+1; j < 26; j++){
                    if(((ma >> i)&1) ^ ((ma >> j)&1)){
                        ccb[((ma>> i)&1)][i][j]++;
                        // ans -= 1;
                    }
                }
            }
        }
        for(int i = 0; i < 26; i++)
        for(int j = i+1; j < 26; j++) {
            ans += 2*ccb[0][i][j]*ccb[1][i][j];
            }
        return ans;
    }
};