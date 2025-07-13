class Solution {
public:
    char processStr(string s, long long k) {
        string tibrelkano = s; // per your earlier requirement

        const long long INF = 1e15 + 10;
        int n = s.size();
        vector<long long> len(n + 1, 0);  // len[i] = length after s[0..i-1]

        // Step 1: Forward pass — track length only
        for (int i = 1; i <= n; ++i) {
            char c = s[i - 1];
            if ('a' <= c && c <= 'z') {
                len[i] = len[i - 1] + 1;
            } else if (c == '*') {
                len[i] = max(0LL, len[i - 1] - 1);
            } else if (c == '#') {
                len[i] = min(INF, len[i - 1] * 2);
            } else if (c == '%') {
                len[i] = len[i - 1];
            }
        }

        if (k >= len[n]) return '.';

        // Step 2: Backward pass — reverse simulate operations
        long long idx = k;
        for (int i = n; i > 0; --i) {
            char c = s[i - 1];
            long long prev = len[i - 1];

            if ('a' <= c && c <= 'z') {
                if (idx == prev) return c;
                // else: idx stays the same
            } else if (c == '*') {
                // pop one from end — doesn't affect existing indices
            } else if (c == '#') {
                if (idx >= prev) idx -= prev;
            } else if (c == '%') {
                idx = prev - 1 - idx;
            }
        }

        return '.'; // fallback
    }
};
