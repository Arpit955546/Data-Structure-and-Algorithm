class Solution {
public:

    // Prime factor contribution of each digit
    // Order: {2, 3, 5, 7}

    int fac[10][4] = {
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2
        {0, 1, 0, 0}, // 3
        {2, 0, 0, 0}, // 4
        {0, 0, 1, 0}, // 5
        {1, 1, 0, 0}, // 6
        {0, 0, 0, 1}, // 7
        {3, 0, 0, 0}, // 8
        {0, 2, 0, 0}  // 9
    };


    /*
        Minimum number of digits required to provide:

        2^a * 3^b * 5^c * 7^d
    */
    int minDigits(int a, int b, int c, int d) {

        // 5 can only come from digit 5
        // 7 can only come from digit 7
        int ans = c + d;


        /*
            First use:

            8 = 2^3
            9 = 3^2

            These are more efficient than using 6.
        */

        ans += a / 3;
        a %= 3;

        ans += b / 2;
        b %= 2;


        /*
            Now:

            a = 0,1,2
            b = 0,1

            If both remain, use 6 = 2*3.
        */

        if (a > 0 && b > 0) {
            ans++;
            a--;
            b--;
        }

        // Remaining 2
        if (a > 0)
            ans++;

        // Remaining 3
        if (b > 0)
            ans++;

        return ans;
    }


    /*
        Build smallest zero-free number of exactly len digits
        satisfying required prime factors.
    */
    string build(int need[4], int len) {

        string ans;
        ans.reserve(len);

        for (int pos = 0; pos < len; pos++) {

            for (int digit = 1; digit <= 9; digit++) {

                int nxt[4];

                for (int j = 0; j < 4; j++) {

                    nxt[j] = max(
                        0,
                        need[j] - fac[digit][j]
                    );
                }

                int remainingSlots = len - pos - 1;


                /*
                    Can the remaining factors be
                    satisfied using remaining positions?
                */

                if (minDigits(
                        nxt[0],
                        nxt[1],
                        nxt[2],
                        nxt[3]
                    ) <= remainingSlots) {

                    ans.push_back(
                        char('0' + digit)
                    );

                    for (int j = 0; j < 4; j++)
                        need[j] = nxt[j];

                    break;
                }
            }
        }

        return ans;
    }


    string smallestNumber(
        string num,
        long long t
    ) {

        // ==========================================
        // 1. Factorize t
        // ==========================================

        int need[4] = {0, 0, 0, 0};

        int primes[4] = {2, 3, 5, 7};

        for (int i = 0; i < 4; i++) {

            while (t % primes[i] == 0) {

                need[i]++;
                t /= primes[i];
            }
        }


        /*
            Digits 1...9 can only generate
            prime factors 2,3,5,7.

            If something remains, impossible.
        */

        if (t != 1)
            return "-1";


        int n = num.size();


        // ==========================================
        // 2. Prefix factor counts
        // ==========================================

        /*
            pref[i][j] = number of prime j factors
            in num[0 ... i-1]

            j:
            0 -> 2
            1 -> 3
            2 -> 5
            3 -> 7
        */

        vector<array<int, 4>> pref(n + 1);

        pref[0] = {0, 0, 0, 0};

        for (int i = 0; i < n; i++) {

            pref[i + 1] = pref[i];

            int digit = num[i] - '0';

            if (digit != 0) {

                for (int j = 0; j < 4; j++) {

                    pref[i + 1][j] +=
                        fac[digit][j];
                }
            }
        }


        // ==========================================
        // 3. Check if num itself is valid
        // ==========================================

        /*
            Find first zero.
            If firstZero == n,
            number is zero-free.
        */

        int firstZero = n;

        for (int i = 0; i < n; i++) {

            if (num[i] == '0') {
                firstZero = i;
                break;
            }
        }


        bool valid = (firstZero == n);

        if (valid) {

            for (int j = 0; j < 4; j++) {

                if (pref[n][j] < need[j]) {

                    valid = false;
                    break;
                }
            }
        }


        if (valid)
            return num;


        // ==========================================
        // 4. Minimum length required
        // ==========================================

        int minLen = minDigits(
            need[0],
            need[1],
            need[2],
            need[3]
        );


        // ==========================================
        // 5. Try to make answer of same length
        // ==========================================

        /*
            IMPORTANT:

            We go RIGHT -> LEFT.

            Example:

                1234

            We want:

                1488

            not:

                2288

            because changing a later digit gives
            a smaller number.
        */

        for (int i = n - 1; i >= 0; i--) {

            /*
                Prefix num[0 ... i-1] must be zero-free.

                firstZero < i means there is a zero
                somewhere in the prefix.
            */

            if (firstZero < i)
                continue;


            int currentDigit = num[i] - '0';


            /*
                Try the smallest digit greater than
                currentDigit.
            */

            for (
                int digit = currentDigit + 1;
                digit <= 9;
                digit++
            ) {

                int rem[4];


                // Factors still required after prefix
                for (int j = 0; j < 4; j++) {

                    rem[j] = max(
                        0,
                        need[j] - pref[i][j]
                    );
                }


                // Remove factors supplied by new digit
                for (int j = 0; j < 4; j++) {

                    rem[j] = max(
                        0,
                        rem[j] - fac[digit][j]
                    );
                }


                int suffixLength = n - i - 1;


                /*
                    Can we fill the suffix?
                */

                if (minDigits(
                        rem[0],
                        rem[1],
                        rem[2],
                        rem[3]
                    ) <= suffixLength) {

                    string ans;

                    ans.reserve(n);

                    // Original prefix
                    ans += num.substr(0, i);

                    // New bigger digit
                    ans.push_back(
                        char('0' + digit)
                    );

                    // Smallest possible suffix
                    ans += build(
                        rem,
                        suffixLength
                    );

                    return ans;
                }
            }
        }


        // ==========================================
        // 6. Same length impossible
        // ==========================================

        /*
            Therefore answer must have more digits.

            It needs at least:
                n + 1

            and also at least:
                minLen

            So:
        */

        int answerLength =
            max(n + 1, minLen);


        return build(
            need,
            answerLength
        );
    }
};