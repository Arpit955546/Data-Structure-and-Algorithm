class Solution {
public:
bool solve(vector<int> &nums,int target,int i,vector<vector<int>> &dp){
    if(target==0){
        return true;
    }
    if(target<0||i>=nums.size()){
        return false;
    }
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    bool take = solve(nums,target-nums[i],i+1,dp);
bool skip = solve(nums,target,i+1,dp);

return dp[i][target]= take || skip;
}
    bool canPartition(vector<int>& nums) {
     
     int sum=0;
     for(int i=0;i<nums.size();i++){
        sum+=nums[i];
     }
     vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,-1)); 
     if(sum%2!=0){
        return false;
     }  
     else
     return solve(nums,sum/2,0,dp);
    }
};