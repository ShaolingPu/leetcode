//link: https://leetcode.com/problems/powerful-integers/

/*
Given two positive integers x and y, an integer is powerful if it is equal to x^i + y^j for some integers i >= 0 and j >= 0.

Return a list of all powerful integers that have value less than or equal to bound.

You may return the answer in any order.  In your answer, each value should occur at most once.

 

Example 1:

Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation: 
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2
Example 2:

Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]
 

Note:
1 <= x <= 100
1 <= y <= 100
0 <= bound <= 10^6
*/

/*
Result:
Runtime: 76 ms, faster than 7.14% of Go online submissions for Powerful Integers.
Memory Usage: 2 MB, less than 100.00% of Go online submissions for Powerful Integers.
*/

func powerfulIntegers(x int, y int, bound int) []int {
    var ans []int
    
    for i := 2; i <= bound; i ++ {
        tmp := 1
        if x == 1 {
            if is_power(y, i - 1) {
                ans = append(ans, i)
            }
        } else {
            for tmp < bound {
                if is_power(y, i - tmp) {
                    ans = append(ans, i)
                    break
                }
                tmp *= x
            }
        }
    }
    return ans
}

func is_power(m, n int) bool {
    t := 1
    if m == 1 && n != 1 {
        return false
    }
    for t < n {
        t *= m
    }
    return t == n
}