//link: https://leetcode.com/problems/first-unique-character-in-a-string/

/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

/*
Result:
Runtime: 56 ms, faster than 84.24% of C++ online submissions for First Unique Character in a String.
Memory Usage: 10.8 MB, less than 100.00% of C++ online submissions for First Unique Character in a String.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26, 0);
        
        for(int i = 0; i < s.length(); i ++){
            v[s[i] - 'a'] ++;
        }
        
        string a = "abcdefghijklmnopqrstuvwxyz";
        for(int i = 0; i < s.length(); i ++){
            if(v[s[i] - 'a'] == 1){
                return i;
            } 
        }
        return -1;
    }
};