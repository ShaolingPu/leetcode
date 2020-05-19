//link: https://leetcode.com/problems/add-to-array-form-of-integer/

/*
For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.

 

Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
Example 4:

Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000
 

Note：
1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
If A.length > 1, then A[0] != 0
*/

/*
Result:
Runtime: 56 ms, faster than 18.37% of Go online submissions for Add to Array-Form of Integer.
Memory Usage: 6.3 MB, less than 100.00% of Go online submissions for Add to Array-Form of Integer.
*/

func addToArrayForm(A []int, K int) []int {
    var length int
    if len(A) > len(strconv.Itoa(K)) {
        length = len(A)
    } else {
        length = len(strconv.Itoa(K))
    }
    
    ans := make([]int, length + 1, length + 1)
    
    carry := 0
    for i, j := length, len(A) - 1; i >= 0; i -- {
        if j >= 0 {
            ans[i] = (A[j] + K % 10 + carry) % 10
            carry = (A[j] + K % 10 + carry) / 10
            j --
            K /= 10
        } else {
            ans[i] = (K % 10 + carry) % 10
            carry = (K % 10 + carry) / 10
            K /= 10
        }
    }
    
    i := 0
    for i < len(ans) && ans[i] == 0 {
        i ++
    }
    if i >= len(ans) {
        return []int{0}
    }
    return ans[i :]
}