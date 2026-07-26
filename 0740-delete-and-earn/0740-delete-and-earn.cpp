class Solution {
public:
int solve(vector<int>  & picks,int i,int mx,vector<int> &dp){
    if(i>mx){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int take=picks[i]+solve(picks,i+2,mx,dp);
    int skip=solve(picks,i+1,mx,dp);
    return dp[i]= max(take,skip);
}
    int deleteAndEarn(vector<int>& nums) {
      vector<int> picks(10001,0);
      int mx=0;
     
      for(int x:nums){
        picks[x]+=x;
        mx=max(mx,x);
      } 
       vector<int> dp(mx+1,-1);
      return solve(picks,0,mx,dp); 


    }
};