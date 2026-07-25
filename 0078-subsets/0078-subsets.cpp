class Solution {
public:
void ps(vector<int>& nums, vector<int> &s,vector<vector<int>> &ans,int i){
    if(i==nums.size()){
        ans.push_back({s});
        return;
    }
    s.push_back(nums[i]);
    ps(nums,s,ans,i+1);
    s.pop_back();
    ps(nums,s,ans,i+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> s;
      ps(nums,s,ans,0);
      return ans;
        
    }
};