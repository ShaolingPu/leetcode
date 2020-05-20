//link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/

/*
Result:
Runtime: 52 ms, faster than 5.13% of C++ online submissions for Kth Smallest Element in a BST.
Memory Usage: 24.4 MB, less than 6.67% of C++ online submissions for Kth Smallest Element in a BST.
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
    vector<int> values;
    int kthSmallest(TreeNode* root, int k) {
        help(root);
        return values[values.size() - k];
    }
    
    void help(TreeNode *root){
        if(!root) {
            return ;
        }
        help(root -> right);
        values.push_back(root -> val);
        help(root -> left);
    }
};