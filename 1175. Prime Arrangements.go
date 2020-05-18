//link: https://leetcode.com/problems/prime-arrangements/

/*
Return the number of permutations of 1 to n so that prime numbers are at prime indices (1-indexed.)

(Recall that an integer is prime if and only if it is greater than 1, and cannot be written as a product of two positive integers both smaller than it.)

Since the answer may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: n = 5
Output: 12
Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5 is at index 1.
Example 2:

Input: n = 100
Output: 682289015
 

Constraints:
1 <= n <= 100
*/

/*
Result:
Runtime: 0 ms, faster than 100.00% of Go online submissions for Prime Arrangements.
Memory Usage: 1.9 MB, less than 100.00% of Go online submissions for Prime Arrangements.
*/

func numPrimeArrangements(n int) int {
    count := 0
    for i := 2; i <= n; i ++ {
        if isPrime(i) {
            count ++
        }
    }
    
    ans := 1
    for i := 2; i <= count; i ++ {
        ans *= i
        ans %= 1000000007
    }
    
    for i := 2; i <= n - count; i ++ {
        ans *= i
        ans %= 1000000007
    }
    
    return ans
}

func isPrime(n int) bool {
    for i := 2; i * i <= n; i ++ {
        if n % i == 0 {
            return false
        }
    }
    return true
}