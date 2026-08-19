class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 9) {
                mp[row] |= (1 << (col - 2));
            }
        }

        int ans = (n - mp.size()) * 2;

        int LEFT  = 0b00001111; // seats 2-5
        int MID   = 0b00111100; // seats 4-7
        int RIGHT = 0b11110000; // seats 6-9

        for (auto &[row, mask] : mp) {
            bool left  = (mask & LEFT) == 0;
            bool mid   = (mask & MID) == 0;
            bool right = (mask & RIGHT) == 0;

            if (left && right)
                ans += 2;
            else if (left || mid || right)
                ans += 1;
        }

        return ans;
    }
};