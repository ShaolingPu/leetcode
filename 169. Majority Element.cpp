//link: https://leetcode.com/problems/majority-element/

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

/*
Result:
Runtime: 52 ms, faster than 33.36% of C++ online submissions for Majority Element.
Memory Usage: 19.6 MB, less than 6.06% of C++ online submissions for Majority Element.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int choice = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i ++){
            if(nums[i] == choice){
                count ++;
            }
            else{
                if(count){
                    count --;
                }
                else{
                    choice = nums[i];
                    count = 1;
                }
            }
        }
        return choice;
    }
};