#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rects) {
        const int MOD = 1e9 + 7;

        // collect unique coordinates
        set<int> xs_set, ys_set;
        for (auto &r : rects) {
            xs_set.insert(r[0]);
            xs_set.insert(r[2]);
            ys_set.insert(r[1]);
            ys_set.insert(r[3]);
        }

        // convert to sorted vectors
        vector<int> xs(xs_set.begin(), xs_set.end());
        vector<int> ys(ys_set.begin(), ys_set.end());

        // mapping (coord → index)
        unordered_map<int,int> xmap, ymap;
        for (int i = 0; i < xs.size(); i++) xmap[xs[i]] = i;
        for (int j = 0; j < ys.size(); j++) ymap[ys[j]] = j;

        // mark coverage
        vector<vector<int>> grid(xs.size(), vector<int>(ys.size(), 0));
        for (auto &r : rects) {
            int x1 = xmap[r[0]], x2 = xmap[r[2]];
            int y1 = ymap[r[1]], y2 = ymap[r[3]];
            for (int i = x1; i < x2; i++)
                for (int j = y1; j < y2; j++)
                    grid[i][j] = 1;
        }

        // compute total area
        long long area = 0;
        for (int i = 0; i + 1 < xs.size(); i++) {
            for (int j = 0; j + 1 < ys.size(); j++) {
                if (grid[i][j]) {
                    long long dx = xs[i+1] - xs[i];
                    long long dy = ys[j+1] - ys[j];
                    area = (area + dx * dy) % MOD;
                }
            }
        }
        return area;
    }
};
