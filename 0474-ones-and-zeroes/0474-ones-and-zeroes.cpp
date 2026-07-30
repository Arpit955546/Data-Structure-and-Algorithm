class Solution {
public:
    int solve(vector<string>& strs, int i, int m, int n,
              vector<vector<vector<int>>>& dp) {
        if (i == strs.size())
            return 0;
        if (dp[i][m][n] != -1)
            return dp[i][m][n];
        int zeros = 0, ones = 0;
        for (char ch : strs[i]) {
            if (ch == '0')
                zeros++;
            else
                ones++;
        }
        int skip = solve(strs, i + 1, m, n, dp);
        int take = 0;
        if (zeros <= m && ones <= n) {
            take = 1 + solve(strs, i + 1, m - zeros, n - ones, dp);
        }

        return dp[i][m][n] = max(take, skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>> dp(
            sz,
            vector<vector<int>>(m + 1, vector<int>(n + 1, -1))
        );
        return solve(strs, 0, m, n, dp);
    }
};