class Solution {
public:

    int solve(int i,int j,vector<int>& piles,vector<vector<int>>& dp){

        if(i==j)
            return piles[i];

        if(dp[i][j]!=-1)
            return dp[i][j];

        int takeLeft = piles[i] - solve(i+1,j,piles,dp);

        int takeRight = piles[j] - solve(i,j-1,piles,dp);

        return dp[i][j]=max(takeLeft,takeRight);
    }

    bool stoneGame(vector<int>& piles) {

        int n=piles.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        return solve(0,n-1,piles,dp)>0;
    }
};