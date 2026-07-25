class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void solve(vector<int> &arr, int idx, int n, int k) {

        if (path.size() == k) {
            ans.push_back(path);
            return;
        }

        for (int i = idx; i < n; i++) {

            path.push_back(arr[i]);

            solve(arr, i + 1, n, k);

            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        vector<int> arr;

        for (int i = 1; i <= n; i++)
            arr.push_back(i);

        solve(arr, 0, n, k);

        return ans;
    }
};