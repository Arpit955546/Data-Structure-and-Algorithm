class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
         int n = nums.size();
         vector<int> ans;

        vector<int> left(n), right(n);

        left[0] = nums[0];
        for(int i = 1; i < n; i++)
            left[i] = left[i-1] + nums[i];

        right[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--)
            right[i] = right[i+1] + nums[i];
      for(int i=0;i<nums.size();i++){
        ans.push_back(abs(left[i]-right[i]));
      } 
      return ans;
    }
};