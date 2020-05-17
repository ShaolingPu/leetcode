//link: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

/*
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

Example 1:
Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
 

Constraints:
1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5
*/

/*
Result:
Runtime: 48 ms, faster than 71.54% of C++ online submissions for Replace Elements with Greatest Element on Right Side.
Memory Usage: 14.6 MB, less than 100.00% of C++ online submissions for Replace Elements with Greatest Element on Right Side.
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        if(n == 0){
            return vector<int>{};
        }
        
        vector<int> v(n, 0);
        n --;
        v[n] = -1;
        int max_ = arr[n];
        
        while(n > 0){
            n --;
            v[n] = max_;
            max_ = max(max_, arr[n]);
        }
        return v;
    }
};