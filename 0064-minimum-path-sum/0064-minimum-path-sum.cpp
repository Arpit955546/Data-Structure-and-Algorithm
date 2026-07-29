class Solution {
public:
int solve(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp,int  m,int n){
    if(i<0||i>m-1||j<0||j>n-1){
        return 1e9;
    }
    if(i==m-1&&j==n-1){
        return grid[i][j];
    }
    if(dp[i][j]!=INT_MIN){
        return dp[i][j];
    }
    int right=solve(grid,i,j+1,dp,m,n);
    int down=solve(grid,i+1,j,dp,m,n);
    return dp[i][j]=grid[i][j]+min(right,down);
    
}
    int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MIN));
      return solve(grid,0,0,dp,m,n); 
    }
};