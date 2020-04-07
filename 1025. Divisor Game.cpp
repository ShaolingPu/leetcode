//link: https://leetcode.com/problems/divisor-game/

/*
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.

 

Example 1:

Input: 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
Example 2:

Input: 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
 

Note:
1 <= N <= 1000
*/

/*
Result:
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Divisor Game.
Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Divisor Game.
*/

class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> v(N + 1, false);
        v[2] = true;
        for(int i = 4; i <= N; i ++){
            for(int j = 1; j <= i / 2; j ++){
                if(i % j == 0 && !v[i - j]){
                    v[i] = true;
                    break;
                }
            }
        }
        return v[N];
    }
};