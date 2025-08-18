class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n  = pairs.size();
        sort(pairs.begin() , pairs.end());
        vector<int> dp(n+1,1);
        for(int i =1;i<=n;i++)
        {
            for(int j =1;j<i;j++)
            {
                if(pairs[j-1][1] <pairs[i-1][0])
                {
                    if(dp[j]+1 > dp[i])
                    {dp[i] = dp[j]+1;}
                }
            }
        }
        int len = *max_element(dp.begin() ,dp.end());
        return len;
    }
};