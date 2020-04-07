//link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

/*
Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)

 

Example 1:
Input: [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: 
We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
 
Note:
The number of nodes in the tree is between 2 and 5000.
Each node will have value between 0 and 100000.
*/

/*
Result:
Runtime: 4 ms, faster than 95.77% of C++ online submissions for Maximum Difference Between Node and Ancestor.
Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Maximum Difference Between Node and Ancestor.
*/

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return help(root, root -> val, root -> val);
    }
    
    int help(TreeNode *root, int min_, int max_){
        if(!root){
            return max_ - min_;
        }
        
        max_ = max(max_, root -> val);
        min_ = min(min_, root -> val);
        
        return max(help(root -> left, min_, max_), help(root -> right, min_, max_));
    }
};