class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n  = grid.size();
        if(grid[0][0] ==1 || grid[n-1][n-1]==1 ){return -1;}
        queue<pair<pair<int,int> ,int>> q;
    vector<vector<int>>  vis( n ,vector<int> (n, 0));
        q.push({{0,0} ,1});
        vis[0][0] =1 ;
        while(!q.empty())
        {
            int x = q.front().first.first;
            int  y = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            if(x==n-1 && y ==n-1){return dis;}
            int dx[8] = {-1 , 0 , 1 ,0 ,-1,-1,1,1};
            int dy[8] = {0,-1,0,1,1,-1,1,-1};
            for(int i =0;i<8;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny])
                {
                    if(grid[nx][ny]!=1)
                    {
                   
                        // q.push({{nx,ny} , dis+2 });
                        // vis[nx][ny] =1;
                    
                    
                        q.push({ {nx,ny } , dis+1});
                        vis[nx][ny] =1;
                    
                    }
                }

            }
        } 
        return -1;
    }
};