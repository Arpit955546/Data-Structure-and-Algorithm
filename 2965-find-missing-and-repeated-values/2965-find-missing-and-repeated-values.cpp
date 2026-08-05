class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
      int m=grid.size();
      int n=grid[0].size();
      long long sum=0;
      long long tsum=0;
      long long sum1=0;
      long long tsum1=0;
      int mis=0;
      int repeat=0;
      long long x=n*n;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sum+=grid[i][j];
            sum1+=grid[i][j]*grid[i][j];
        }
      }
      tsum=x*(x+1)/2;
      tsum1=x*(x+1)*(2*x+1)/6;
      long long a=tsum-sum;
      long long b=(tsum1-sum1)/(tsum-sum);
      mis=-(a-b)/2;
      repeat=(a+b)/2;
      return {mis,repeat};
    }
};