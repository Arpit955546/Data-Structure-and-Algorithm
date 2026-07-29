class Solution {
public:

    int solve(vector<int>& stones, int i, int sum1, 
              int totalSum, vector<vector<int>>& dp) {

        if(i == stones.size()) {
            int sum2 = totalSum - sum1;
            return abs(sum1 - sum2);
        }

        if(dp[i][sum1] != -1) {
            return dp[i][sum1];
        }


        // take current stone
        int take = solve(stones, i+1, 
                         sum1 + stones[i],
                         totalSum, dp);


        // skip current stone
        int skip = solve(stones, i+1,
                         sum1,
                         totalSum, dp);


        return dp[i][sum1] = min(take, skip);
    }


    int lastStoneWeightII(vector<int>& stones) {

        int n = stones.size();

        int totalSum = 0;

        for(int x : stones)
            totalSum += x;


        vector<vector<int>> dp(
            n,
            vector<int>(totalSum + 1, -1)
        );


        return solve(stones, 0, 0, totalSum, dp);
    }
};