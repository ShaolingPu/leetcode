//link: https://leetcode.com/problems/reformat-the-string/

/*
Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return the reformatted string or return an empty string if it is impossible to reformat the string.


Example 1:

Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
Example 2:

Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.
Example 3:

Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.
Example 4:

Input: s = "covid2019"
Output: "c2o0v1i9d"
Example 5:

Input: s = "ab123"
Output: "1a2b3"
 
Constraints:
1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.
*/

/*
Runtime: 12 ms, faster than 96.26% of C++ online submissions for Reformat The String.
Memory Usage: 7.5 MB, less than 100.00% of C++ online submissions for Reformat The String.
*/

class Solution {
public:
    string reformat(string s) {
        
        int count_a = 0, count_n = 0;
        for(int i = 0; i < s.length(); i ++){
            if(s[i] <= 'z' && s[i] >= 'a'){
                count_a ++;
            }
            else{
                count_n ++;
            }
        }
        
        if(abs(count_a - count_n) > 1){
            return "";
        }
        
        string ans = "";
        for(int i = 0; i < s.length(); i ++){
            ans += " ";
        }
        
        bool flag = false;    //start with alpha
        if(count_n < count_a){
            flag = true;
        }
        
        int i = 1;
        int j = 0;
        
        if(flag){
            i = 0;
            j = 1;
        }
        for(int k = 0; k < s.length(); k ++){
            if(s[k] >= 'a' && s[k] <= 'z'){
                ans[i] = s[k];
                i += 2;
            }
            else{
                ans[j] = s[k];
                j += 2;
            }
        }
        return ans;
    }
};