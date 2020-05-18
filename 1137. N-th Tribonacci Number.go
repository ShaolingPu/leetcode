//link: https://leetcode.com/problems/n-th-tribonacci-number/

/*
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

 

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537
 

Constraints:
0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
*/

/*
Result:
Runtime: 0 ms, faster than 100.00% of Go online submissions for N-th Tribonacci Number.
Memory Usage: 2 MB, less than 100.00% of Go online submissions for N-th Tribonacci Number.
*/

func tribonacci(n int) int {
    if n < 2 {
        return n
    }
    
    if n == 2 {
        return 1
    }
    
    t0, t1, t2 := 0, 1, 1
    
    for n > 2{
        t0, t1, t2 = t1, t2, t0 + t1 + t2
        n --
    }
    
    return t2
    
}