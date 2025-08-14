class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> f(27,0);
        int l =0,r=0;
        int ans =0;
        while(r<n)
        {
            f[s[r]-'A'+1]++;
            int maxf = *max_element( f.begin()  ,  f.end() );
            while(r-l+1 - maxf >k)
            {f[s[l]-'A'+1]--;l++;}
            if(r-l+1 -maxf<=k)
            {
            ans = max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};