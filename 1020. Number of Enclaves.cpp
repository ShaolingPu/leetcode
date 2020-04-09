//link: https://leetcode.com/problems/number-of-enclaves/

/*
Given a 2D array A, each cell is 0 (representing sea) or 1 (representing land)

A move consists of walking from one land square 4-directionally to another land square, or off the boundary of the grid.

Return the number of land squares in the grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:

Input: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: 
There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed because its on the boundary.
Example 2:

Input: [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: 
All 1s are either on the boundary or can reach the boundary.
 

Note:
1 <= A.length <= 500
1 <= A[i].length <= 500
0 <= A[i][j] <= 1
All rows have the same size.
*/

/*
Result:
Runtime: 1852 ms, faster than 5.01% of C++ online submissions for Number of Enclaves.
Memory Usage: 190.2 MB, less than 6.25% of C++ online submissions for Number of Enclaves.
*/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        
        queue<pair<int, int>> q;
        
        int temp[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        
        for(int i = 0; i < m; i ++){
            if(A[i][0]){
                q.push(make_pair(i, 0));
            }
            if(A[i][n - 1]){
                q.push(make_pair(i, n - 1));
            }
        }
        
        for(int i = 0; i < n; i ++){
            if(A[0][i]){
                q.push(make_pair(0, i));
            }
            if(A[m - 1][i]){
                q.push(make_pair(m - 1, i));
            }
        }
        
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            A[i][j] = 0;
            for(int k = 0; k < 4; k ++){
                if(i + temp[k][0] > 0 && i + temp[k][0] < m - 1 && j + temp[k][1] > 0 && j + temp[k][1] < n - 1 && A[i + temp[k][0]][j + temp[k][1]]){
                    q.push(make_pair(i + temp[k][0], j + temp[k][1]));
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(A[i][j]){
                    ans ++;
                }
            }
        }
        return ans;
    }
    
};