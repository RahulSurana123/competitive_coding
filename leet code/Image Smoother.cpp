

/* 
    Solution by Rahul Surana
    
    ***********************************************************


An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image 
by rounding down the average of the cell and 
the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). 
If one or more of the surrounding cells of a cell is not present, 
we do not consider it in the average (i.e., the average of the four cells in the red smoother).


Given an m x n integer matrix img representing the grayscale of an image, 
return the image after applying the smoother on each cell of it.


    ***********************************************************
*/

class Solution {
public:

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> t(n,vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int c=0,s=0;
                for(int k = i-1 ; k <= i+1; k++){
                    for(int l = j-1 ; l <= j+1; l++){
                        if(k<0 || l < 0 || l >=m || k >=n ) continue;
                        c++;
                        s += img[k][l];        
                    }   
                }
                t[i][j] = s/c; 
            }
        }
        return t;
    }
};