class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max = LLONG_MIN;
        long long semax = LLONG_MIN;
        long long third_max = LLONG_MIN;

        // First max
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }

        // Second max (distinct)
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > semax && nums[i] < max) {
                semax = nums[i];
            }
        }

        // Third max (distinct)
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > third_max && nums[i] < semax) {
                third_max = nums[i];
            }
        }

        // If third max does not exist
        if (third_max == LLONG_MIN)
            return max;

        return third_max;
    }
};