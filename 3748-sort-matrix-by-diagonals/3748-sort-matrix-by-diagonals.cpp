class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n =grid.size();
        vector<vector<int>> ans(n, vector<int>(n));
        map<int, vector<int>> mp;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                mp[j-i].push_back(grid[i][j]);
            }
        }
for (auto it = mp.begin(); it != mp.end(); it++) {
    int ele = it->first;
    vector<int> v = it->second;
    sort(v.begin(), v.end());
    if (ele > 0) { reverse(v.begin(), v.end()); }
    it->second = v;   // ❌ error: `it->second` is a `const` reference
}
           for(int i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
               int ele =j-i;
               ans[i][j] = mp[ele].back();
               mp[ele].pop_back();
            }
        }
        return ans;
    }
};