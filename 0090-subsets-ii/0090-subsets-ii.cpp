class Solution {
public:
void ps(vector<int>& nums, vector<int> &s,vector<vector<int>> &ans,int i){
    
    if(i==nums.size()){
        ans.push_back({s});
        return;
    }
    s.push_back(nums[i]);
    ps(nums,s,ans,i+1);
    int idx=i;
    while(idx+1<nums.size()&&nums[idx]==nums[idx+1]){
        idx++;
    }
    s.pop_back();
    ps(nums,s,ans,idx+1);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> s;
      ps(nums,s,ans,0);
      return ans;
        
    }
};