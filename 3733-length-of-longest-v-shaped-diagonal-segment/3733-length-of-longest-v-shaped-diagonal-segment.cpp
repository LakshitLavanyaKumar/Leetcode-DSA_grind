class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<vector<int> > > dp(n,vector<vector<int> > (m,vector<int> (4,0)));
        int ff =0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(v[i][j]!=1){
                    
                    for(int k = 0;k<4;k++){
                        dp[i][j][k] = 1;
                    }
                } else {
                    ff = 1;
                }
            }
        }
        if(!ff){
            return 0;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(v[i][j] == 2){
                    if(i>0 && j<m-1){
                        if(v[i-1][j+1] == 0){
                            dp[i][j][0] += dp[i-1][j+1][0];
                        }
                    }
                    if(i>0 && j>0){
                        if(v[i-1][j-1] == 0){
                            dp[i][j][3] += dp[i-1][j-1][3];
                        }
                    }
                } else if(v[i][j] == 0) {
                    if(i>0 && j<m-1){
                        if(v[i-1][j+1] == 2){
                            dp[i][j][0] += dp[i-1][j+1][0];
                        }
                    }
                    if(i>0 && j>0){
                        if(v[i-1][j-1] == 2){
                            dp[i][j][3] += dp[i-1][j-1][3];
                        }
                    }
                }
                // cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<" "<<dp[i][j][2]<<" "<<dp[i][j][3]<<endl;
            }
        }
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(v[i][j] == 2){
                    if(i<n-1 && j>0){
                        if(v[i+1][j-1] == 0){
                            dp[i][j][2] += dp[i+1][j-1][2];
                        }
                    }
                    if(i<n-1 && j<m-1){
                        if(v[i+1][j+1] == 0){
                            dp[i][j][1] += dp[i+1][j+1][1];
                        }
                    }
                } else if(v[i][j] == 0) {
                    if(i<n-1 && j>0){
                        if(v[i+1][j-1] == 2){
                            dp[i][j][2] += dp[i+1][j-1][2];
                        }
                    }
                    if(i<n-1 && j<m-1){
                        if(v[i+1][j+1] == 2){
                            dp[i][j][1] += dp[i+1][j+1][1];
                        }
                    }
                }
                // cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<" "<<dp[i][j][2]<<" "<<dp[i][j][3]<<endl;
            }
        }
        // if(n>2 && m>3)
        // cout<<dp[0][4][1]<<endl;
        int ans = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(v[i][j] == 1){
                    int x = i;
                    int y = j;
                    int t = 0;
                    int path = 1;
                    while(x>0 && y<(m-1)){
                        int f = 0;
                        if(t%2==0){
                            if(v[x-1][y+1] == 2){
                                f = 1;
                                if(i==1 && y==3){
                                    cout<<dp[x-1][y+1][1]<<endl;
                                }
                                ans = max(ans,path + dp[x-1][y+1][1]);
                                path++;
                            }
                        } else {
                            if(v[x-1][y+1] == 0){
                                f = 1;
                                ans = max(ans,path + dp[x-1][y+1][1]);
                                path++;
                            }
                        }
                        x--;
                        y++;
                        t++;
                        if(!f){
                            break;
                        }
                        ans = max(ans,path);
                    }
                    x = i;
                    y = j;
                    t = 0;
                    path = 1;
                    while(x<(n-1) && y<(m-1)){
                        int f = 0;
                        if(t%2==0){
                            if(v[x+1][y+1] == 2){
                                f = 1;
                                ans = max(ans,path + dp[x+1][y+1][2]);
                                path++;
                            }
                        } else {
                            if(v[x+1][y+1] == 0){
                                f = 1;
                                ans = max(ans,path + dp[x+1][y+1][2]);
                                path++;
                            }
                        }
                        x++;
                        y++;
                        t++;
                        if(!f){
                            break;
                        }
                        ans = max(ans,path);
                    }
                    x = i;
                    y = j;
                    t = 0;
                    path = 1;
                    while(x<(n-1) && y>0){
                        int f = 0;
                        if(t%2==0){
                            if(v[x+1][y-1] == 2){
                                f = 1;
                                ans = max(ans,path + dp[x+1][y-1][3]);
                                path++;
                            }
                        } else {
                            if(v[x+1][y-1] == 0){
                                f = 1;
                                ans = max(ans,path + dp[x+1][y-1][3]);
                                path++;
                            }
                        }
                        x++;
                        y--;
                        t++;
                        if(!f){
                            break;
                        }
                        ans = max(ans,path);
                    }
                    x = i;
                    y = j;
                    t = 0;
                    path = 1;
                    while(x>0 && y>0){
                        int f = 0;
                        if(t%2==0){
                            if(v[x-1][y-1] == 2){
                                f = 1;
                                ans = max(ans,path + dp[x-1][y-1][0]);
                                path++;
                            }
                        } else {
                            if(v[x-1][y-1] == 0){
                                f = 1;
                                ans = max(ans,path + dp[x-1][y-1][0]);
                                path++;
                            }
                        }
                        x--;
                        y--;
                        t++;
                        if(!f){
                            break;
                        }
                        ans = max(ans,path);
                    }
                }
            }
        }
        return ans;
    }
};