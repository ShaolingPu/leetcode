//link: https://leetcode.com/problems/camelcase-matching/

/*
A query word matches a given pattern if we can insert lowercase letters to the pattern word so that it equals the query. (We may insert each character at any position, and may insert 0 characters.)

Given a list of queries, and a pattern, return an answer list of booleans, where answer[i] is true if and only if queries[i] matches the pattern.

 

Example 1:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation: 
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
Example 2:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation: 
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
Example 3:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation: 
"FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".
 

Note:
1 <= queries.length <= 100
1 <= queries[i].length <= 100
1 <= pattern.length <= 100
All strings consists only of lower and upper case English letters.
*/

/*
Result:
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Camelcase Matching.
Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Camelcase Matching.
*/

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(int i = 0; i < queries.size(); i ++){
            if(match(queries[i], pattern)){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
    
    bool match(string s, string p){
        int i = 0;
        int j = 0;
        while(i < s.length() && j < p.length()){
            if(s[i] == p[j]){
                i ++;
                j ++;
            }
            else{
                if(s[i] >= 'a' && s[i] <= 'z'){
                    i ++;
                }
                else{
                    return false;
                }
            }
        }
        
        if(j < p.length()){
            return false;
        }
        
        if(i < s.length()){
            while(i < s.length() && s[i] >= 'a' && s[i] <= 'z') {
                i ++;
            }
        }
        
        if(i < s.length()){
            return false;
        }
        
        return true;
    }
};