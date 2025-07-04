class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n =s1.length();
        int n1 = s2.length();
        int m = s3.length();
vector<vector<vector<bool>>> dp(
    n + 1, vector<vector<bool>>(
        n1 + 1,vector<bool>(m + 1, false)
    )
);
for(int j =1;j<=n1;j++)
{
for(int k =1;k<=m;k++)
{
    if(s2.substr(0,j) == s3.substr(0,k))
    {
    dp[0][j][k] = true;
    }
}
}
for(int i =1;i<=n;i++)
{
for(int k =1;k<=m;k++)
{
    if(s1.substr(0,i) == s3.substr(0,k))
    {
    dp[i][0][k] = true;
    }
}
}
        dp[0][0][0] = true;
        for(int i =1;i<=n;i++)
        {
            for(int j =1;j<=n1;j++)
            {
                for(int k =1;k<=m;k++)
                {
                    if(s1[i-1]!=s3[k-1] && s2[j-1]!=s3[k-1])
                    {dp[i][j][k] = false;}
                    else if(s1[i-1]==s3[k-1] && s2[j-1]==s3[k-1])
                    {dp[i][j][k] = (dp[i][j-1][k-1] | dp[i-1][j][k-1]);}
                    else if(s1[i-1]==s3[k-1])
                    {dp[i][j][k] = dp[i-1][j][k-1];}
                    else if(s2[j-1]==s3[k-1])
                    {dp[i][j][k]  = dp[i][j-1][k-1];}
                }
            }
        }
        return dp[n][n1][m];
    }
};