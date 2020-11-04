/**
A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing, and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.
**/

/**
Runtime: 356 ms, faster than 81.02% of C++ online submissions for Even Odd Tree.
Memory Usage: 152.9 MB, less than 5.11% of C++ online submissions for Even Odd Tree.
**/


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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        
        int min_max = 0;
        q.push(root);
        int level = 1;
        int count = 1;
        while(!q.empty()){
            TreeNode *t = q.front();
            q.pop();
            count --;
            if(t -> left){
                q.push(t -> left);
            }
            if(t -> right){
                q.push(t -> right);
            }
            if(level % 2){
                if(t -> val % 2 == 0 || min_max >= t -> val){
                    return false;
                }
                min_max = t -> val;
            }
            else{
                if(t -> val % 2 || min_max <= t -> val){
                    return false;
                }
                min_max = t -> val;
            }
            if(count == 0){
                level ++;
                count = q.size();
                if(level % 2){
                    min_max = 0;
                }
                else{
                    min_max = 1000000;
                }
            }
        }
        return true;
    }
};
