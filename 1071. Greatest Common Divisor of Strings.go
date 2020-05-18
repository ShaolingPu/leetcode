//link: https://leetcode.com/problems/greatest-common-divisor-of-strings/

/*
For strings S and T, we say "T divides S" if and only if S = T + ... + T  (T concatenated with itself 1 or more times)

Return the largest string X such that X divides str1 and X divides str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Note:

1 <= str1.length <= 1000
1 <= str2.length <= 1000
str1[i] and str2[i] are English uppercase letters.
*/

/*
Result:
Runtime: 0 ms, faster than 100.00% of Go online submissions for Greatest Common Divisor of Strings.
Memory Usage: 2.9 MB, less than 100.00% of Go online submissions for Greatest Common Divisor of Strings.
*/

func gcdOfStrings(str1 string, str2 string) string {
    var n int
    if len(str1) < len(str2) {
        n = len(str1)
    } else {
        n = len(str2)
    }
    
    ans := 0
    
    for i := 1; i <= n; i ++ {
        if len(str1) % i == 0 && len(str2) % i == 0 && str1[: i] == str2[: i] {
            if strings.Repeat(str1[: i], len(str1) / i) == str1 && strings.Repeat(str1[: i], len(str2) / i) == str2 {
                if i > ans {
                    ans = i
                }
            }
        }
    }
    
    return str1[: ans]
}