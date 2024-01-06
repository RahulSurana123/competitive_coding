



/* 
    Solution by Rahul Surana
    
    ***********************************************************


On a 2D plane, we place n stones at some integer coordinate points. 
Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same 
column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, 
return the largest possible number of stones that can be removed.

 

    ***********************************************************
*/



class Solution {
public:
    
    void df(int i, int x, vector<int> &p,vector<bool> &v,vector<vector<int>>& stones){
        if(v[x]) return;
        v[x] = true;
        p[x] = i;
        for(int j = 0; j < stones.size(); j++){
            if(!v[j] && (stones[j][0] == stones[x][0] || stones[j][1] == stones[x][1])){
                df(i,j,p,v,stones);
            }
        }
    }
    
    int parent(int a, vector<int> &p){
        if(a == p[a]) return a;
        return p[a] = parent(p[a],p);
    }
    
    int removeStones(vector<vector<int>>& stones) {
        if(stones.size()==1) return 0;
        vector<int> p(stones.size()+1,-1);
        vector<bool> v(stones.size()+1,false);
        int k =0;
        for(int i = 0; i < stones.size(); i++){
            if(!v[i]){
                df(k++,i,p,v,stones);
            }
        }
        map<int,int> m;
        for(int i = 0 ; i < p.size()-1; i++){  m[p[i]]++; }
        return stones.size() - m.size();
    }
};