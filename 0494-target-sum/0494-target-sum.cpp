class Solution {
public:
    int solve(vector<int> &nums, int target, int i,
              vector<vector<int>> &dp, int offset) {

        if (target < -offset || target > offset)
            return 0;

        if (i == nums.size()) {
            return target == 0;
        }

        if (dp[i][target + offset] != -1) {
            return dp[i][target + offset];
        }

        int x = solve(nums, target + nums[i], i + 1, dp, offset);
        int y = solve(nums, target - nums[i], i + 1, dp, offset);

        return dp[i][target + offset] = x + y;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;
        for (int x : nums) {
            sum += x;
        }

        if (abs(target) > sum)
            return 0;

        int offset = sum;

        vector<vector<int>> dp(nums.size() + 1,
                               vector<int>(2 * sum + 1, -1));

        return solve(nums, target, 0, dp, offset);
    }
};