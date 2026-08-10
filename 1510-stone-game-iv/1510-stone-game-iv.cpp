#include <vector>

class Solution {
public:
    bool winnerSquareGame(int n) {
        // dp[i] stores whether the current player can win with i stones left
        std::vector<bool> dp(n + 1, false);
        
        // Iteratively compute winning and losing states for all pile sizes
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k * k <= i; ++k) {
                // If removing k*k stones forces the opponent into a losing state,
                // the current player can win.
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break; // Move found, no need to check other square numbers
                }
            }
        }
        
        return dp[n];
    }
};
