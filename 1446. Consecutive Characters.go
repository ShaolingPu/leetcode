//link: https://leetcode.com/problems/consecutive-characters/

/*
Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return the power of the string.

 

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
Example 3:

Input: s = "triplepillooooow"
Output: 5
Example 4:

Input: s = "hooraaaaaaaaaaay"
Output: 11
Example 5:

Input: s = "tourist"
Output: 1
 

Constraints:
1 <= s.length <= 500
s contains only lowercase English letters.
*/

/*
Result:
Runtime: 0 ms, faster than 100.00% of Go online submissions for Consecutive Characters.
Memory Usage: 2.3 MB, less than 100.00% of Go online submissions for Consecutive Characters.
*/

func maxPower(s string) int {
    i := 0
    j := 1
    ans := 0
    count := 1
    for ; j < len(s); {
        if s[i] == s[j] {
            j ++
            count ++
        }else{
            i = j
            count = 1
            j ++;
        }
        if count > ans{
            ans = count
        }
    }
    if count > ans{
        ans = count
    }
    
    return ans
}