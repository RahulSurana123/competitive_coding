

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], 
return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.


    ***********************************************************
    
*/

class Solution {
public:
    vector<bool> vis;
    bool df(int i, vector<int>& lC, vector<int>& rC){
        if(vis[i]) return false;
        vis[i] = true;
        if(lC[i] != -1 && rC[i] != -1) return df(lC[i],lC,rC) && df(rC[i],lC,rC);
        else if(lC[i] != -1) return df(lC[i],lC,rC);
        else if(rC[i] != -1) return df(rC[i],lC,rC);
        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vis.resize(n,true);
        for(int i = 0 ; i < n; i++){
            if(leftChild[i] != -1) {
                if(!vis[leftChild[i]]) return false;
                vis[leftChild[i]] = false;
            }
            if(rightChild[i] != -1) {
                if(!vis[rightChild[i]]) return false;
                vis[rightChild[i]] = false;
            }
        }
        int root = -1, c = 0;
        for(int i = 0 ; i < n; i++) { if(vis[i]){ root = i; c++; } }
        if(c>1) return false;
        if(root == -1)  return false;
        vis[root] = false;
        bool ans = df(root,leftChild,rightChild);
        for(int i = 0 ; i < n; i++) {  if(!vis[i]) return false; }
        return ans;
    }
};