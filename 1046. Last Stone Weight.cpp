//link: https://leetcode.com/problems/last-stone-weight/

/*
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

Example 1:
Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
 
Note:
1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight.
Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Last Stone Weight.
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        vector<int> v(1001, 0);
        
        for(int i = 0; i < stones.size(); i ++){
            v[stones[i]] ++;
        }
        
        int k = 1000;
        int j;
        while(k > 0){
            j = k - 1;
            if(v[k] > 1){
                v[k] %= 2;
            }
            if(v[k]){
                while(j > 0 && v[j] == 0){
                    j --;
                }
                if(j <= 0){
                    return k;
                }
                v[k - j] ++;
                v[j] --;
                k = max(k - j, j);
            }
            else{
                k --;
            }
        }
        return 0;
    }
};