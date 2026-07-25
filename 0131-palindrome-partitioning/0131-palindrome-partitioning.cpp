class Solution {
public:
    bool ispallindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void backtrack(string s, vector<vector<string>>& res, vector<string>& ans,
                   int i, int j) {
        if (i == s.size()) {
            res.push_back(ans);
            return;
        }
        if (j == s.size()) {
            return;
        }
        if (ispallindrome(s, i, j)) {
            string temp = s.substr(i, j - i + 1);
            ans.push_back(temp);
            backtrack(s, res, ans, j + 1, j + 1);
            ans.pop_back();
        }
        backtrack(s, res, ans, i, j + 1);
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> res;
        vector<string> ans;

        backtrack(s, res, ans, 0, 0);

        return res;
    }
};