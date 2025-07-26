class Solution {
public:
const int MOD = 1000000007;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
     int m = grid.size();
     int n = grid[0].size();
     
        vector<vector<int>> v(m , vector<int>( n ));
        vector<vector<int>> v1(m , vector<int>( n ));
        v = grid;
        for(int i =0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                v[i][j] = (v[i][j])%k;
            }
        }
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n , vector<int> (k+1)));
dp[0][0][grid[0][0]%k]=1;
 for(int i =0;i<m;i++)
 {
    for(int j =0;j<n;j++)
    {
        for(int p=0;p<=k;p++)
        {
            int val = (p+v[i][j])%k;
          if(i>0)dp[i][j][val] = (dp[i][j][val]+ dp[i-1][j][p])%MOD;
if(j>0)dp[i][j][val] = (dp[i][j][val]+ dp[i][j-1][p])%MOD;
        }
    }
 }
 return dp[m-1][n-1][0];
    }
};