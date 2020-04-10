//link: https://leetcode.com/problems/convert-to-base-2/

/*
Given a number N, return a string consisting of "0"s and "1"s that represents its value in base -2 (negative two).

The returned string must have no leading zeroes, unless the string is "0".

 

Example 1:

Input: 2
Output: "110"
Explantion: (-2) ^ 2 + (-2) ^ 1 = 2
Example 2:

Input: 3
Output: "111"
Explantion: (-2) ^ 2 + (-2) ^ 1 + (-2) ^ 0 = 3
Example 3:

Input: 4
Output: "100"
Explantion: (-2) ^ 2 = 4
 

Note:
0 <= N <= 10^9
*/

/*
Result:
Runtime: 4 ms, faster than 21.99% of C++ online submissions for Convert to Base -2.
Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Convert to Base -2.
*/

class Solution {
public:
    string baseNeg2(int N) {
        string ans = "";
        bool even = true;
        if(N == 0){
            return "0";
        }
        while(N > 0){
            if(even){
                ans = to_string(N % 2) + ans;
                N /= 2;
                even = false;
            }
            else{
                ans = to_string(N % 2) + ans;
                N = N + (N % 2);
                N /= 2;
                even = true;
            }
        }
        return ans;
    }
};
