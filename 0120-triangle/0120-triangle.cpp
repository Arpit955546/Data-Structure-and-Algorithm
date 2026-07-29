class Solution {
public:
    int solve(vector<vector<int>>& triangle, int i, int j,
              vector<vector<int>>& dp) {

        int n = triangle.size();

        // last row
        if(i == n-1) {
            return triangle[i][j];
        }

        if(dp[i][j] != INT_MIN) {
            return dp[i][j];
        }

        int down = solve(triangle, i+1, j, dp);
        int diagonal = solve(triangle, i+1, j+1, dp);

        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }


    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

        return solve(triangle, 0, 0, dp);
    }
};