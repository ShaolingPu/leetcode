//link: https://leetcode.com/problems/flood-fill/

/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/

/*
Result:
Runtime: 36 ms, faster than 5.82% of C++ online submissions for Flood Fill.
Memory Usage: 14.1 MB, less than 11.11% of C++ online submissions for Flood Fill.
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int t[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        queue<pair<int, int>> q;
        
        q.push(make_pair(sr, sc));
        
        int color = image[sr][sc];
        
        if(color == newColor){
            return image;
        }
        
        while(!q.empty()){
            pair<int, int> p = q.front();
            image[p.first][p.second] = newColor;
            q.pop();
            
            for(int i = 0; i < 4; i ++){
                if(p.first + t[i][0] >= 0 && p.first + t[i][0] < image.size() && p.second + t[i][1] >= 0 && p.second + t[i][1] < image[0].size() && image[p.first + t[i][0]][p.second + t[i][1]] == color){
                    q.push(make_pair(p.first + t[i][0], p.second + t[i][1]));
                }
            }
        }
        return image;
    }
};