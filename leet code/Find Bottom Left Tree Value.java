

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a binary tree, return the leftmost value in the last row of the tree.


    ***********************************************************
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans = 0, al = -1;

    public void df(TreeNode r, int l){
        if(r == null) return;
        if(r.left == null && r.right == null){
            if(l > al){
                ans = r.val;
                al = l;
            }
            return;
        }
        df(r.left,l+1);
        df(r.right,l+1);
    }

    public int findBottomLeftValue(TreeNode root) {
        df(root,0);
        return ans;
    }
}