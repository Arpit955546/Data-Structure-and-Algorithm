class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> cnt(128, 0);
        int left = 0, ans = 0;

        for (int right = 0; right < s.size(); right++) {
            cnt[s[right]]++;

            while (cnt[s[right]] > 2) {
                cnt[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};