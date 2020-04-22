//link: https://leetcode.com/problems/string-matching-in-an-array/

/*
Given an array of string words. Return all strings in words which is substring of another word in any order. 

String words[i] is substring of words[j], if can be obtained removing some characters to left and/or right side of words[j].

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
Example 3:

Input: words = ["blue","green","bu"]
Output: []
 

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
It's guaranteed that words[i] will be unique.
*/

/*
Runtime: 8 ms, faster than 82.73% of C++ online submissions for String Matching in an Array.
Memory Usage: 9 MB, less than 100.00% of C++ online submissions for String Matching in an Array.
*/

bool cmp(string s1, string s2){
    return s1.length() < s2.length();
}

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> ans;
        sort(words.begin(), words.end(), cmp);
        
        for(int i = 0; i < words.size() - 1; i ++){
            for(int j = i + 1; j < words.size(); j ++){
                if(words[j].find(words[i]) != -1){
                    ans.insert(words[i]);
                }
            }
        }
        
        vector<string> v(ans.begin(), ans.end());
        return v;
        
    }
};