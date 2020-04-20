//link: https://leetcode.com/problems/total-hamming-distance/

/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.
*/


/*
Result:
Runtime: 80 ms, faster than 31.21% of C++ online submissions for Total Hamming Distance.
Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Total Hamming Distance.
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> v(30, 0);
        
        for(int i = 0; i < nums.size(); i ++){
            int cur = nums[i];
            int index = 0;
            while(cur != 0){
                v[index] += (cur % 2);
                index ++;
                cur >>= 1;
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i ++){
            int cur = nums[i];
            int index = 0;
            while(cur != 0){
                if(cur % 2){
                    ans += (nums.size() - v[index]); 
                }
                // else{
                //     ans += v[index];
                // }
                index ++;
                cur >>= 1;
            }
        }
        return ans;
    }
};