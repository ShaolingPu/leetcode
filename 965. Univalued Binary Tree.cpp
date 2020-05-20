//link: https://leetcode.com/problems/univalued-binary-tree/submissions/

/*
A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.

 

Example 1:


Input: [1,1,1,1,1,null,1]
Output: true
Example 2:


Input: [2,2,2,5,2]
Output: false
 

Note:
The number of nodes in the given tree will be in the range [1, 100].
Each node's value will be an integer in the range [0, 99].
*/

/*
Result:
Runtime: 4 ms, faster than 49.55% of C++ online submissions for Univalued Binary Tree.
Memory Usage: 9.9 MB, less than 100.00% of C++ online submissions for Univalued Binary Tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int flag = false;
    int v;
    bool isUnivalTree(TreeNode* root) {
        if(!flag){
            v = root -> val;
            flag = true;
        }
        if(!root) {
            return true;
        }
        return root -> val == v && isUnivalTree(root -> left) && isUnivalTree(root -> right);
    }
};