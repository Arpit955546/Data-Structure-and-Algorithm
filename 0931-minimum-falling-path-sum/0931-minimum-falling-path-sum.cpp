class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(j < 0 || j >= n)
            return 1e9;

        if(i == m-1)
            return matrix[i][j];

        if(dp[i][j] != INT_MIN)
            return dp[i][j];

        int down = solve(matrix, i+1, j, dp);
        int left = solve(matrix, i+1, j-1, dp);
        int right = solve(matrix, i+1, j+1, dp);

        return dp[i][j] = matrix[i][j] + min(down, min(left, right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MIN));

        int ans = 1e9;

        for(int j = 0; j < n; j++) {
            ans = min(ans, solve(matrix, 0, j, dp));
        }

        return ans;
    }
};