
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        // last[j] = word2[j] ko right side se
        // match karne wala index in word1
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        // Right to left matching
        while (i >= 0 && j >= 0) {

            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }

            i--;
        }

        vector<int> ans;

        bool mismatchUsed = false;
        j = 0;

        // Left to right greedy
        for (i = 0; i < n && j < m; i++) {

            // Exact match
            if (word1[i] == word2[j]) {

                ans.push_back(i);
                j++;
            }

            // One mismatch allowed
            else if (!mismatchUsed &&
                     (j == m - 1 || i < last[j + 1])) {

                ans.push_back(i);
                j++;
                mismatchUsed = true;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};
