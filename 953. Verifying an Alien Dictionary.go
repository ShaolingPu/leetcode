//link: https://leetcode.com/problems/verifying-an-alien-dictionary/

/*
In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.
*/

/*
Result:
Runtime: 0 ms, faster than 100.00% of Go online submissions for Verifying an Alien Dictionary.
Memory Usage: 2.7 MB, less than 100.00% of Go online submissions for Verifying an Alien Dictionary.
*/

var m map[byte]int

func isAlienSorted(words []string, order string) bool {
    m = make(map[byte]int)
    for i := 0; i < len(order); i ++ {
        m[order[i]] = i
    }    
    
    for i := len(words) - 1; i >= 1; i -- {
        if !is_ordered(words[i - 1], words[i]) {
            return false
        }
    }
    return true
}


func is_ordered(s1, s2 string) bool{
    l := len(s1)
    if(len(s2) < len(s1)){
        l = len(s2)
    }
    
    for i := 0; i < l; i ++ {
        if m[s1[i]] > m[s2[i]] {
            return false
        } else if m[s1[i]] < m[s2[i]] {
            return true
        }
    }
    return len(s1) <= len(s2)
}