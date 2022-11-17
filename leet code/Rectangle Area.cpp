



/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the coordinates of two rectilinear rectangles in a 2D plane, 
return the total area covered by the two rectangles.

The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).

The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).

 

    ***********************************************************
*/



class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int z = (min(bx2,ax2)-max(ax1,bx1));
        int y = (min(by2,ay2)-max(ay1,by1));
        // cout << ((ax2-ax1)*(ay2-ay1)) + ((bx2-bx1)*(by2-by1)) <<" "<<z <<"\n";
        return (((ax2-ax1)*(ay2-ay1)) + ((bx2-bx1)*(by2-by1))) - ((z < 0 || y < 0)? 0 : z*y);
    }
};