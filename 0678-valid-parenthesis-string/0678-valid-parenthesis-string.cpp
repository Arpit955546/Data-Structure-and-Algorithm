class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for(char c : s) {

            if(c == '(') {
                low++;
                high++;
            }

            else if(c == ')') {
                low--;
                high--;
            }

            else { // '*'
                low--;
                high++;
            }

            // Minimum cannot be negative
            low = max(0, low);

            // Even maximum is negative
            if(high < 0)
                return false;
        }

        return low == 0;
    }
};