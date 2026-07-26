class Solution {
public:
int solve(vector<int> nums,int i,int n,vector<int> &dp){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int take =nums[i]+solve(nums,i+2,n,dp);
    int skip=solve(nums,i+1,n,dp);
    return dp[i]=max(take,skip);
}
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> dp1(nums.size()+1,-1);
        vector<int> dp2(nums.size()+1,-1);
      int x= solve(nums,0,nums.size()-1,dp1);
      int y=solve(nums,1,nums.size(),dp2);
      return max(x,y);  
    }
};