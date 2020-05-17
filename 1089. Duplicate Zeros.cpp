//link: https://leetcode.com/problems/duplicate-zeros/

/*
Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.

 

Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]
 
Note:
1 <= arr.length <= 10000
0 <= arr[i] <= 9
*/

/*
Runtime: 12 ms, faster than 86.64% of C++ online submissions for Duplicate Zeros.
Memory Usage: 10 MB, less than 100.00% of C++ online submissions for Duplicate Zeros.
*/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> ans(arr.size(), 0);
        
        int count = 0;
        for(int i = 0; i < arr.size(); i ++){
            if(arr[i] && i + count < arr.size()){
                ans[i + count] = arr[i];
            }
            else{
                count ++;
            }
        }
        arr = ans;
    }
};