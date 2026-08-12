class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int res = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            m[nums[right]]++;
            while(m[nums[right]] > k){
                m[nums[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }

        return res;
    }
};