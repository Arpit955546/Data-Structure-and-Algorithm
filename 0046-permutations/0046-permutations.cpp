class Solution {
public:
   void solve(vector<int> &nums,vector<vector<int>> &ans,vector<int> &path,vector<int> &vis){
    if(path.size()==nums.size()){
        ans.push_back(path);
    }
    for(int i=0;i<nums.size();i++){
        if(vis[i]==1){
            continue;
        }
        vis[i]=1;
        path.push_back(nums[i]);
        solve(nums,ans,path,vis);
        vis[i]=0;
        path.pop_back();
    }
   }
    vector<vector<int>> permute(vector<int>& nums) {
    vector<int> path;
    vector<int> vis(nums.size(),0);
    vector<vector<int>> ans;
     solve(nums,ans,path,vis);
     return ans;   
    }
};