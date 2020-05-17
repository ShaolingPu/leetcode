//link: https://leetcode.com/problems/ransom-note/

/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:
You may assume that both strings contain only lowercase letters.
*/

/*
Result:
Runtime: 32 ms, faster than 88.93% of C++ online submissions for Ransom Note.
Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Ransom Note.
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v(26, 0);
        
        for(int i = 0; i < magazine.length(); i ++){
            v[magazine[i] - 'a'] ++;
        }
        
        for(int i = 0; i < ransomNote.length(); i ++){
            if(v[ransomNote[i] - 'a']){
                v[ransomNote[i] - 'a'] --;
            }
            else{
                return false;
            }
        }
        return true;
    }
};