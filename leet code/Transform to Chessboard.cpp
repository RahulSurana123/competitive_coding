
/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given an n x n binary grid board. In each move, you can swap any two rows with each other, or any two columns with each other.
Return the minimum number of moves to transform the board into a chessboard board. If the task is impossible, return -1.
A chessboard board is a board where no 0's and no 1's are 4-directionally adjacent.


    ***********************************************************
*/


class Solution {
public:
    int movesToChessboard(vector<vector<int>>& b) {
        int n = b.size();
      for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){
            if(b[0][0] ^ b[0][j] ^ b[i][0] ^ b[i][j]) return -1;
         }
      }
      int rowSum = 0;
      int colSum = 0;
      int rowSwap = 0;
      int colSwap = 0;
      for(int i = 0; i < n; i++){
         rowSum += b[i][0];
         colSum += b[0][i];
         rowSwap += b[i][0] == i % 2;
         colSwap += b[0][i] == i % 2;
      }
      if(rowSum != n/2 && rowSum != (n + 1)/2)return -1;
      if(colSum != n/2 && colSum != (n + 1)/2)return -1;
      if(n % 2 == 1){
         if(colSwap % 2) colSwap = n - colSwap;
         if(rowSwap % 2) rowSwap = n - rowSwap;
      }else{
         colSwap = min(colSwap, n - colSwap);
         rowSwap = min(rowSwap, n - rowSwap);
      }
      return (rowSwap + colSwap)/2;
        
    }
};