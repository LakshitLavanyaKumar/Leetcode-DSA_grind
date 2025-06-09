class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        
        dist[0][0] = 1;
        q.push({1, 0, 0}); // {distance, x, y}

        int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
        int dy[8] = {0, -1, 0, 1, 1, -1, 1, -1};

        while (!q.empty()) {
            auto [d, x, y] = q.top(); q.pop();
            if (x == n - 1 && y == n - 1) return d;

            if (d > dist[x][y]) continue;

            for (int i = 0; i < 8; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                    if (d + 1 < dist[nx][ny]) {
                        dist[nx][ny] = d + 1;
                        q.push({dist[nx][ny], nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};
