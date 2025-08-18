class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m  = s2.length();int tot =0;
        vector<vector<int> > dp(n+1  , vector<int> (m+1  ));
        for(int i =m-1;i>=0;i--)
        {tot+=s2[i];
            dp[n][i] = tot;
        }
        int h =0;
        for(int i =n-1;i>=0;i--)
        {h+=s1[i];dp[i][m] = h;tot+=s1[i];}
        for(int i =n-1;i>=0;i--)
        {
            for(int j =m-1;j>=0;j--)
            {
                if(s1[i] == s2[j])
                {dp[i][j] = dp[i+1][j+1];}
                else {
                    dp[i][j] = min(s1[i]+dp[i+1][j] ,s2[j]+ dp[i][j+1] );
                }
            }
        }
        return  dp[0][0] ;
    }
};