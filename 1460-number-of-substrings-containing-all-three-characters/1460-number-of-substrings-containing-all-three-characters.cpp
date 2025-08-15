class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        long long int k = (long long )((long long)n*((long long)n+1))/2LL;
        int l =0;
        int r =0;
        map<char,int> mp;
        long long int ans =0;
        while(r<n)
        {
            mp[s[r]]++;;
            while(mp.size()>2 &&l<r)
            {mp[s[l]]--;
            if(mp[s[l]]==0)
            {mp.erase(s[l]);}l++;
            }
            long long int j = r-l+1;
            ans+=j;
            r++;
        }
        return (int)(k-ans);
    }
};