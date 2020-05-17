//link: https://leetcode.com/problems/remove-k-digits/

/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

/*
Result:
Runtime: 808 ms, faster than 5.22% of C++ online submissions for Remove K Digits.
Memory Usage: 300.8 MB, less than 9.09% of C++ online submissions for Remove K Digits.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int i = 0;
        
        string ret = "";
        
        int need = num.length() - k;
        
        if(need == 0){
            return "0";
        }
        
        while(i < num.length()){
            int j = i + 1;
            int flag = false;
            
            while(j < num.length() &&  num.length() - j >= need){
                if(num[j] < num[i]){
                    flag = true;
                }
                j ++;
            }
            if(!flag && need){
                ret = ret + num[i];
                need --;
            }
            i ++;
        }
        
        int j = 0;
        while(j < ret.length() - 1 && ret[j] == '0'){
            j ++;
        }
        ret = ret.substr(j);
        
        return ret;
    }
};