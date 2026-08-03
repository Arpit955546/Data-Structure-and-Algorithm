class Solution {
public:
    int solve(int i, vector<int>& stoneValue, vector<int>& dp) {
        int n = stoneValue.size();

        if (i >= n)
            return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int take = 0;
        int ans = INT_MIN;

        for (int k = 0; k < 3 && i + k < n; k++) {
            take += stoneValue[i + k];
            ans = max(ans, take - solve(i + k + 1, stoneValue, dp));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n, INT_MIN);

        int diff = solve(0, stoneValue, dp);

        if (diff > 0)
            return "Alice";
        if (diff < 0)
            return "Bob";

        return "Tie";
    }
};