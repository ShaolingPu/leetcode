//link: https://leetcode.com/problems/jewels-and-stones/

/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.
*/

/*
Result:
Runtime: 4 ms, faster than 64.52% of C++ online submissions for Jewels and Stones.
Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Jewels and Stones.
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<bool> isJewel_a(26, false);
        vector<bool> isJewel_A(26, false);
        
        for(int i = 0; i < J.length(); i ++){
            if(J[i] >= 'a' && J[i] <= 'z'){
                isJewel_a[J[i] - 'a'] = true;
            }
            else{
                isJewel_A[J[i] - 'A'] = true;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < S.length(); i ++){
            if(S[i] >= 'a' && S[i] <= 'z'){
                if(isJewel_a[S[i] - 'a']){
                    ans ++;
                }
            }
            else{
                if(isJewel_A[S[i] - 'A']){
                    ans ++;
                }
            }
        }
        
        return ans;
    }
};