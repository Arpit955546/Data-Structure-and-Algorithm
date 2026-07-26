class Solution {
public:
int ways(vector<int> &cost,int i,vector<int> & dp){
    int n=cost.size();

    if(i>=n){
        return 0;
    }
if(dp[i]!=-1){
    return dp[i];
}
    
    return dp[i]= min(cost[i]+ways(cost,i+1,dp),cost[i]+ways(cost,i+2,dp));
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
      return min( ways(cost,0,dp),ways(cost,1,dp)); 
    }
};