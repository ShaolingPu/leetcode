//link: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

/*
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

 

Example 1:

Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

Note:
The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.
*/

/*
Runtime: 8 ms, faster than 60.68% of C++ online submissions for Sum of Root To Leaf Binary Numbers.
Memory Usage: 14.5 MB, less than 100.00% of C++ online submissions for Sum of Root To Leaf Binary Numbers.
*/

class Solution {
public:
    int ans = 0;
    int sumRootToLeaf(TreeNode* root) {
        help(root);
        return ans;
    }
    
    void help(TreeNode *root){
        if(!root){
            return ;
        }
        if(root -> left){
            root -> left -> val += root -> val << 1;
            help(root -> left);
        }
        if(root -> right){
            root -> right -> val += root -> val << 1;
            help(root -> right);
        }
        
        if(!root -> left && !root -> right){
            ans += root -> val;
        }
    }
};
