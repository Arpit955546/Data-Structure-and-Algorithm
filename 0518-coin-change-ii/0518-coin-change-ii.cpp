class Solution {
public:
int solve(vector<int> &coins,int amount,int  n,int i,vector<vector<int>> &dp){
    if(amount==0){
        return 1;
    }
    if(i>=n||amount<0){
        return 0;
    }
    if(dp[i][amount]!=-1){
        return dp[i][amount];
    }
    int take=solve(coins,amount-coins[i],n,i,dp);
    int skip=solve(coins,amount,n,i+1,dp);
    return dp[i][amount]= take+skip;
}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return solve(coins,amount,coins.size(),0,dp);
    }
};