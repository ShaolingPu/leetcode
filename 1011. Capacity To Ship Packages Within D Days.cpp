//link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

/*
A conveyor belt has packages that must be shipped from one port to another within D days.

The i-th package on the conveyor belt has a weight of weights[i].  Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
Output: 15
Explanation: 
A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed. 
Example 2:

Input: weights = [3,2,2,4,1,4], D = 3
Output: 6
Explanation: 
A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], D = 4
Output: 3
Explanation: 
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
 
Note:
1 <= D <= weights.length <= 50000
1 <= weights[i] <= 500
*/

/*
Result:
Runtime: 144 ms, faster than 5.51% of C++ online submissions for Capacity To Ship Packages Within D Days.
Memory Usage: 68.8 MB, less than 11.11% of C++ online submissions for Capacity To Ship Packages Within D Days.
*/


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int high = 25000000;
        int low = 0;
        while(low <= high){
            int mid = (high + low) / 2;
            if(valid(mid, weights, D) && !valid(mid - 1, weights, D)){
                return mid;
            }
            if(valid(mid, weights, D)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }
    
    bool valid(int capacity, vector<int> w, int D){
        int day = 0;
        int count = 0;
        int i = 0;
        while(i < w.size()){
            if(w[i] > capacity){
                return false;
            }
            count += w[i];
            if(count == capacity){
                day ++;
                count = 0;
            }
            else if(count > capacity){
                day ++;
                count = w[i];
            }
            i ++;
        }
        if(count > 0){
            day ++;
        }
        return day <= D;
    }
};