class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "", word = "";
        
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else {
                if (!word.empty()) {
                    if (!ans.empty()) ans = word + " " + ans;
                    else ans = word;
                    word = "";
                }
            }
        }

        // Add last word
        if (!word.empty()) {
            if (!ans.empty()) ans = word + " " + ans;
            else ans = word;
        }

        return ans;
    }
};
