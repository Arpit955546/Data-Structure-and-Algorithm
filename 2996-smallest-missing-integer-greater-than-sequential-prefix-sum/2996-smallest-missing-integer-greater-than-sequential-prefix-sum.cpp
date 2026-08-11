class Solution {
public:
    int missingInteger(vector<int>& nums) {
         // Step 1: Find longest sequential prefix
        int prefixSum = nums[0];
        int i = 1;
        while (i < nums.size() && nums[i] == nums[i-1] + 1) {
            prefixSum += nums[i];
            i++;
        }

        // Step 2: Find smallest integer > prefixSum not in nums
        unordered_set<int> st(nums.begin(), nums.end());
        int candidate = prefixSum;
        while (st.count(candidate)) {
            candidate++;
        }
        return candidate;   
    }
};