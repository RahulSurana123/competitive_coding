

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of strings equations that represent relationships between variables 
where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".
Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.



    ***********************************************************
*/


class Solution {
public:
    
    map<char,char> p;
    
    int get_p(char a){
        if(a == p[a]) return a;
        return p[a] = get_p(p[a]);
    }
    
    bool equationsPossible(vector<string>& e) {
        for(int i = 0; i < e.size(); i++){
            if(p.find(e[i][0]) == p.end()){
                p[e[i][0]] = e[i][0];
            }
             if(p.find(e[i][3]) == p.end()){
                p[e[i][3]] = e[i][3];
            }
            if(e[i][1] == '='){
                char a = get_p(e[i][0]);
                char b = get_p(e[i][3]);
                p[a] = b;
             }
            
        }
         for(int i = 0; i < e.size(); i++){
             if(e[i][1] == '!'){
                char a = get_p(e[i][0]);
                char b = get_p(e[i][3]);
                if(a == b) return false;
             }
         }
        return true;
    }
};