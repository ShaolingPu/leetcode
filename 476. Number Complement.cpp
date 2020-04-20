//link: https://leetcode.com/problems/number-complement/

/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
Example 1:

Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 

Example 2:

Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 
Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/
*/

/*
Result:
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number Complement.
Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Number Complement.
*/

class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int plus = 1;
        while(num != 1){
            ans += (1 - num % 2) * plus;
            plus *= 2;
            num /= 2;
        }
        return ans;
    }
};