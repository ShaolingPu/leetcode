//link: https://leetcode.com/problems/di-string-match/

/*
Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.

Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

If S[i] == "I", then A[i] < A[i+1]
If S[i] == "D", then A[i] > A[i+1]
 

Example 1:

Input: "IDID"
Output: [0,4,1,3,2]
Example 2:

Input: "III"
Output: [0,1,2,3]
Example 3:

Input: "DDI"
Output: [3,2,0,1]
 

Note:
1 <= S.length <= 10000
S only contains characters "I" or "D".
*/

/*
Result:
Runtime: 8 ms, faster than 17.50% of Go online submissions for DI String Match.
Memory Usage: 5.1 MB, less than 100.00% of Go online submissions for DI String Match.
*/

func diStringMatch(S string) []int {
    ans := make([]int, len(S) + 1, len(S) + 1)
    
    h := len(S)
    l := 0
    
    for i := 0; i < len(S); i ++ {
        if S[i] == 'I' {
            ans[i] = l
            l ++
        } else {
            ans[i] = h
            h --
        }
    }
    
    ans[len(S)] = l;
    return ans
    
}