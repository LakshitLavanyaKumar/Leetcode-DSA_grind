class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m ,vector<int>(n,INT_MAX));
priority_queue<
    pair<int, pair<int,int>>,                // T
    vector<pair<int, pair<int,int>>>,        // Container
    greater<pair<int, pair<int,int>>>        // Compare
> pq;
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
             
             int dx[] = {1,0,-1,0};
             int dy[] = {0,1,0,-1};
             for(int i =0;i<4;i++)
             {
                int nr = r+dx[i];
                int nc = c+dy[i];
                if(nr<m && nr>=0 && nc<n && nc >=0)
                {
                    if(grid[nr][nc] == 1)
                    {
                        if(1+dist[r][c]<dist[nr][nc])
                        {
                            dist[nr][nc] = 1+dist[r][c];
                            pq.push({dist[nr][nc],{nr,nc}});
                        }
                    }
                    else{
                         if(dist[r][c]<dist[nr][nc])
                        {
                            dist[nr][nc] = dist[r][c];
                            pq.push({dist[nr][nc],{nr,nc}});
                        }
                    }
                }
             }
        }
        return dist[m-1][n-1];
    }
};