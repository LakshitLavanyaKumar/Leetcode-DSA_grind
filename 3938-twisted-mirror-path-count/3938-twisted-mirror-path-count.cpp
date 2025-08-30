class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9+7;
        int m = grid.size();
        int n = grid[0].size();
      //  map<pair<int,int>,pair<int,int>> mp;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n , vector<int>(2)));
         dp[m-1][n-1][0] = dp[m-1][n-1][1] = 1;
        //direction is which dir it is coming from
        // for(int i =0;i<m;i++)
        //     {
        //         if(grid[i][0] == 1)
        //         {dp[i][0][0] =1;break;}
        //         dp[i][0][0] = 1;
        //     }

        //  for(int i =0;i<n;i++)
        //     {
        //         if(grid[0][i] == 1)
        //         {dp[0][i][1] =1;break;}
        //         dp[0][i][1] = 1;
        //     }
        for(int i=m-1;i>=0;i--)
            {
                for(int j=n-1;j>=0;j--)
                    {
                        if (i == m-1 && j == n-1) continue;
                        // if(grid[i][j] ==1)
                        // {
                        //     mp[{i,j}] = {dp[i-1][j],dp[i][j-1]};continue;
                            
                        // }
                        // if(grid[i-1][j]==1 && i>1 && grid[i][j-1] == 1 && j>1)
                        // {
                        //     dp[i][j] = dp[i-1][j-1];continue;
                        // }
                        // int up = dp[i-1][j];
                        // if(grid[i-1][j]==1 && i>1)
                        // {
                            
                        //     up = mp[{i-1,j}].second;
                        // }
                        //     int left = dp[i][j-1];
                        //     if(grid[i][j-1] == 1 && j>1)
                        //     {
                               
                        //     //up = mp[{k+1,j-1}].second;
                        //         left = mp[{i,j-1}].first;
                        //     }
                        if(grid[i][j] == 1)
                        {
                           int down = i+1<m?dp[i+1][j][1]:0;
                           int right = j+1<n?dp[i][j+1][0]:0;
                            dp[i][j][0] = (down % MOD);
                    dp[i][j][1] = (right % MOD);continue;
                        }
                        // //left se aane k tarike
                        // dp[i][j][0] = (dp[i][j-1][0]+dp[i][j-1][1])%MOD;
                        // dp[i][j][1] = (dp[i-1][j][0]+dp[i-1][j][1])%MOD;
                        // not everytime
 int down  = (i+1 < m) ? dp[i+1][j][1] : 0;
                    int right = (j+1 < n) ? dp[i][j+1][0] : 0;
                    int sum = (int)((down + right) % MOD);
                    dp[i][j][0] = sum;
                    dp[i][j][1] = sum;
                                
                    }
            }

                        return (dp[0][0][0] )%MOD;
    }
};