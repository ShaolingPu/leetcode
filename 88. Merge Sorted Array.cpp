//link: https://leetcode.com/problems/merge-sorted-array/

/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

/*
Result:
Runtime: 4 ms, faster than 81.54% of C++ online submissions for Merge Sorted Array.
Memory Usage: 9.1 MB, less than 6.52% of C++ online submissions for Merge Sorted Array.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size() - 1;

        m --;
        n --;
        while(n >= 0 && m >= 0){
            if(nums1[m] > nums2[n]){
                nums1[i --] = nums1[m];
                m --;
            }
            else{
                nums1[i --] = nums2[n];
                n --;
            }
        }
        
        while(n >= 0){
            nums1[i --] = nums2[n];
            n --;
        }
    }
};