//link: https://leetcode.com/problems/destination-city/

/*
You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

 

Example 1:

Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
Example 2:

Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".
Example 3:

Input: paths = [["A","Z"]]
Output: "Z"
 

Constraints:
1 <= paths.length <= 100
paths[i].length == 2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
All strings consist of lowercase and uppercase English letters and the space character.
*/

/*
Result:
Runtime: 4 ms, faster than 92.27% of Go online submissions for Destination City.
Memory Usage: 4.3 MB, less than 100.00% of Go online submissions for Destination City.
*/

func destCity(paths [][]string) string {
    m := make(map[string]string)
    
    for i := 0; i < len(paths); i ++{
        m[paths[i][0]] = paths[i][1]
    }
    
    for i := 0; i < len(paths); i ++{
        if _, ok := m[paths[i][1]]; !ok {
            return paths[i][1]
        }
    }
    return ""
}