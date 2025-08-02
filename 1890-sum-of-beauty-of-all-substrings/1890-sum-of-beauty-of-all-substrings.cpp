class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int c = 0;
        
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int ma = INT_MIN, mi = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        ma = max(ma, freq[k]);
                        mi = min(mi, freq[k]);
                    }
                }
                c += (ma - mi);
            }
        }
        return c;
    }
};
