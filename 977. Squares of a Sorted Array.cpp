//link: https://leetcode.com/problems/squares-of-a-sorted-array/

/*
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

 

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Note:
1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
*/

/*
Result:
Runtime: 80 ms, faster than 85.03% of C++ online submissions for Squares of a Sorted Array.
Memory Usage: 25.8 MB, less than 5.40% of C++ online submissions for Squares of a Sorted Array.
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans(A.size(), 0);
        int low = 0;
        int high = A.size() - 1;
        
        int index = high;
        while(low <= high){
            if(abs(A[high]) > abs(A[low])){
                ans[index] = A[high] * A[high];
                high --;
            }
            else{
                ans[index] = A[low] * A[low];
                low ++;
            }
            index --;
        }
        return ans;
    }
};