class Solution {
public:
    long long LIMIT = 1e6 + 5;

    // Calculate nCr but stop if it exceeds LIMIT
    long long comb(int n, int r) {
        if (r < 0 || r > n) return 0;

        r = min(r, n - r);
        long long res = 1;

        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;

            if (res > LIMIT)
                return LIMIT;
        }

        return res;
    }


    // Count number of unique permutations of half
    long long countPerm(vector<int>& cnt, int len) {
        long long ans = 1;
        int used = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i]) {
                ans = min(LIMIT, ans * comb(used + cnt[i], cnt[i]));
                used += cnt[i];
            }
        }

        return ans;
    }


    string smallestPalindrome(string s, long long k) {

        vector<int> freq(26);

        for(char c : s)
            freq[c-'a']++;


        string mid = "";

        vector<int> half(26);

        for(int i=0;i<26;i++) {

            if(freq[i]%2)
                mid = char(i+'a');

            half[i] = freq[i]/2;
        }


        // total possible palindromes
        long long total = countPerm(half, s.size()/2);

        if(k > total)
            return "";


        string left = "";
        int remaining = s.size()/2;


        // Greedy construction of left half
        while(remaining--) {

            for(int ch=0; ch<26; ch++) {

                if(half[ch]==0)
                    continue;


                // choose this character temporarily
                half[ch]--;

                long long ways = countPerm(half, remaining);


                if(k > ways) {

                    // skip these ways
                    k -= ways;
                    half[ch]++;
                }
                else {

                    // character belongs here
                    left += char('a'+ch);
                    break;
                }
            }
        }


        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};