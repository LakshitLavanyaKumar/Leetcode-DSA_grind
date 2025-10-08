class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int dp[101][101][101];
        memset( dp , 0 , sizeof( dp ) ) ;
        for(int  len =1;len<=n;len++)
        {
            for(int i = n-len;i>=0;i--)
            {
                int j = i+len-1;
                for(int k=0;k<n;k++)
                {
                    int cnt =1;
                    while(i+cnt<=j && boxes[i+cnt]==boxes[i]){cnt++;}

                    int best = ((k+cnt)*(k+cnt)) + (i+cnt<=j?dp[i+cnt][j][0]:0);

                    for(int m = i+cnt;m<=j;m++)
                    {
                        if(boxes[m] == boxes[i])
                        {
                            int val = dp[i+cnt][m-1][0]+(k+cnt<=n?dp[m][j][k+cnt]:0);
                            best = max(best ,val);
                        }
                    }
                    dp[i][j][k] = best;
                }

            }
        }
    return dp[0][n-1][0];
    }
};