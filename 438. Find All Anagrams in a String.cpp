//link: https://leetcode.com/problems/find-all-anagrams-in-a-string/

/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

/*
Result:
Runtime: 32 ms, faster than 71.67% of C++ online submissions for Find All Anagrams in a String.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Find All Anagrams in a String.
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        
        vector<int> ans;
        
        if(s.length() < p.length()){
            return ans;
        }
        
        
        for(int i = 0; i < p.length(); i ++){
            v1[s[i] - 'a'] ++;
            v2[p[i] - 'a'] ++;
        }
        
        if(v1 == v2){
            ans.push_back(0);
        }
        
        for(int j = 1; j <= s.length() - p.length(); j ++){
            v1[s[j - 1] - 'a'] --;
            v1[s[j + p.length() -1] - 'a'] ++;
            if(v1 == v2){
                ans.push_back(j);
            }
        }
        return ans;
    }
};