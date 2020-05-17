//link: https://leetcode.com/problems/single-element-in-a-sorted-array/

/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

/*
Result:
Runtime: 36 ms, faster than 33.67% of C++ online submissions for Single Element in a Sorted Array.
Memory Usage: 11.1 MB, less than 7.14% of C++ online submissions for Single Element in a Sorted Array.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i ++){
            ans ^= nums[i];
        }
        return ans;
    }
};