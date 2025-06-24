class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        int n = coords.size();
        long long maxi = 0;

        vector<vector<int>> xaxis = coords;
        sort(xaxis.begin(), xaxis.end());
        for (int i = 0; i < n;) {
            int x = xaxis[i][0];
            int y0 = xaxis[i][1], y1 = xaxis[i][1];
            int j = i;
            while (j < n && xaxis[j][0] == x) {
                y0 = min(y0, xaxis[j][1]);
                y1 = max(y1, xaxis[j][1]);
                j++;
            }
            if (y1 != y0) {
                int width = max(abs(x - xaxis[0][0]), abs(x - xaxis[n - 1][0]));
                maxi = max(maxi, 1LL * (y1 - y0) * width);
            }
            i = j;
        }

        vector<vector<int>> yaxis = coords;
        sort(yaxis.begin(), yaxis.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        for (int i = 0; i < n;) {
            int y = yaxis[i][1];
            int x0 = yaxis[i][0], x1 = yaxis[i][0];
            int j = i;
            while (j < n && yaxis[j][1] == y) {
                x0 = min(x0, yaxis[j][0]);
                x1 = max(x1, yaxis[j][0]);
                j++;
            }
            if (x1 != x0) {
                int height = max(abs(y - yaxis[0][1]), abs(y - yaxis[n - 1][1]));
                maxi = max(maxi, 1LL * (x1 - x0) * height);
            }
            i = j;
        }
        return (maxi==0)?-1:maxi;  
    }
};