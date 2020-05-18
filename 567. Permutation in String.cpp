//link: https://leetcode.com/problems/permutation-in-string/

/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

/*
Result:
Runtime: 20 ms, faster than 48.15% of C++ online submissions for Permutation in String.
Memory Usage: 7.2 MB, less than 100.00% of C++ online submissions for Permutation in String.
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        
        //vector<int> ans;
        
        if(s2.length() < s1.length()){
            return false;
        }
        
        
        for(int i = 0; i < s1.length(); i ++){
            v1[s1[i] - 'a'] ++;
            v2[s2[i] - 'a'] ++;
        }
        
        if(v1 == v2){
            return true;
        }
        
        for(int j = 1; j <= s2.length() - s1.length(); j ++){
            v2[s2[j - 1] - 'a'] --;
            v2[s2[j + s1.length() -1] - 'a'] ++;
            if(v1 == v2){
                return true;
            }
        }
        return false;
    }
};