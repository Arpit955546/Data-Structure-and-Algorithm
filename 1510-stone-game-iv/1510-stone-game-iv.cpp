
class Solution {
public:
    bool winnerSquareGame(int n) {

        vector<bool> dp(n + 1, false);

        // dp[0] = false
        // No stones -> current player loses

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j * j <= i; j++) {

                // Remove j*j stones
                // If opponent reaches a losing state,
                // current player wins.
                if (dp[i - j * j] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
