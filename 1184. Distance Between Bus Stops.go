//link: https://leetcode.com/problems/distance-between-bus-stops/

/*
A bus has n stops numbered from 0 to n - 1 that form a circle. We know the distance between all pairs of neighboring stops where distance[i] is the distance between the stops number i and (i + 1) % n.

The bus goes along both directions i.e. clockwise and counterclockwise.

Return the shortest distance between the given start and destination stops.

 

Example 1:



Input: distance = [1,2,3,4], start = 0, destination = 1
Output: 1
Explanation: Distance between 0 and 1 is 1 or 9, minimum is 1.
 

Example 2:



Input: distance = [1,2,3,4], start = 0, destination = 2
Output: 3
Explanation: Distance between 0 and 2 is 3 or 7, minimum is 3.
 

Example 3:



Input: distance = [1,2,3,4], start = 0, destination = 3
Output: 4
Explanation: Distance between 0 and 3 is 6 or 4, minimum is 4.
 

Constraints:
1 <= n <= 10^4
distance.length == n
0 <= start, destination < n
0 <= distance[i] <= 10^4
*/

/*
Result:
Runtime: 0 ms, faster than 100.00% of Go online submissions for Distance Between Bus Stops.
Memory Usage: 2.8 MB, less than 100.00% of Go online submissions for Distance Between Bus Stops.
*/

func distanceBetweenBusStops(distance []int, start int, destination int) int {
    for i := 1; i < len(distance); i ++ {
        distance[i] += distance[i - 1]
    }
    
    if start > destination {
        start, destination = destination, start
    }
    
    if start > 0 {
        if distance[destination - 1] - distance[start - 1] < distance[len(distance) - 1] + distance[start - 1] - distance[destination - 1] {
            return distance[destination - 1] - distance[start - 1]
        }
        return distance[len(distance) - 1] + distance[start - 1] - distance[destination - 1]
    } else {
        if distance[destination - 1] < distance[len(distance) - 1] - distance[destination - 1] {
            return distance[destination - 1]
        }
        return distance[len(distance) - 1] - distance[destination - 1]
    }
}