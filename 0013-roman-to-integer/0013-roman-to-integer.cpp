#include <string>
#include <map>

class Solution {
public:
    int romanToInt(string s) {
        // Use a map<char, int> for efficiency.
        std::map<char, int> mp = {
            {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int ans = 0;
        // Start by adding the value of the last character.
        ans = mp[s.back()];

        // Iterate from the second-to-last character to the beginning.
        for (int i = s.length() - 2; i >= 0; i--) {
            // If the current numeral is smaller than the one to its right, subtract it.
            if (mp[s[i]] < mp[s[i+1]]) {
                ans -= mp[s[i]];
            } 
            // Otherwise, add it.
            else {
                ans += mp[s[i]];
            }
        }
        return ans;
    }
};