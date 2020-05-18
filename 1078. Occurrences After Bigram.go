//link: https://leetcode.com/problems/occurrences-after-bigram/

/*
Given words first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.

For each such occurrence, add "third" to the answer, and return the answer.

 

Example 1:

Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]
Example 2:

Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]
 

Note:

1 <= text.length <= 1000
text consists of space separated words, where each word consists of lowercase English letters.
1 <= first.length, second.length <= 10
first and second consist of lowercase English letters.
*/

/*
Result:
Runtime: 0 ms, faster than 100.00% of Go online submissions for Occurrences After Bigram.
Memory Usage: 2 MB, less than 100.00% of Go online submissions for Occurrences After Bigram.
*/

func findOcurrences(text string, first string, second string) []string {
    list := strings.Split(text, " ")
    
    var ans []string
    for i := 0; i < len(list) - 2; i ++ {
        if list[i] == first && list[i + 1] == second {
            ans = append(ans, list[i + 2])
        }
    }
    return ans
}