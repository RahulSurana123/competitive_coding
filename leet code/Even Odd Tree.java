

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.


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
    public boolean isEvenOddTree(TreeNode root) {
        int mult = 1, oe = 1;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int size = q.size();
            int prev = Integer.MIN_VALUE;
            while(size-- > 0){
                TreeNode n = q.poll();
                if(n.val%2 != oe || (mult *n.val) <= (mult * prev)) return false;
                // System.out.println((mult *n.val) +" <= "+(mult * prev.val));
                prev = n.val;
                if(n.left != null) q.add(n.left);
                if(n.right != null) q.add(n.right);
            }
            mult *= -1;
            oe = 1 - oe;
            // System.out.println(mult +" "+oe);
        }
        return true;
    }
}