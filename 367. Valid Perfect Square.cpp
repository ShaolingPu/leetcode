//link: https://leetcode.com/problems/valid-perfect-square/

/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Example 2:

Input: num = 14
Output: false
 

Constraints:
1 <= num <= 2^31 - 1
*/

/*
Result:
Runtime: 4 ms, faster than 10.20% of C++ online submissions for Valid Perfect Square.
Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Valid Perfect Square.
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1){
            return true;
        }
        int high = num / 2;
        int low = 1;
        
        while(low <= high){
            int mid = (high + low) / 2;
            if(mid == num / mid && num % mid == 0){
                return true;
            }
            else if(mid > num / mid){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }
};