class Solution {
public:
int solve(vector<int> &arr,int n,vector<int> &dp){
    if(n==0){
        return 0;
    }
    if(n<0){
        return 1e9;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=1e9;
    for(int i=0;i<arr.size();i++){
       int ar=arr[i];
ans=min(ans,1+solve(arr,n-ar,dp));

    }
    return dp[n]=ans;
}
    int numSquares(int n) {
        vector<int> arr;
      for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j*j==i){
                arr.push_back(i);
            }
        }
      } 
      vector<int> dp(n+1,-1);
     int ans=solve(arr,n,dp);
      if(ans>=1e9){
        return -1;
      }
      else{
        return ans;
      } 
    }
};