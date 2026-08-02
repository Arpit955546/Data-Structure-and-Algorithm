class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        vector<int> ans;

        for (int i = 1; i <= nums.size(); i++) {
            if (mp.find(i) == mp.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};