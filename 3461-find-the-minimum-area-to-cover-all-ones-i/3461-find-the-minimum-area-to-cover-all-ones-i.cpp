class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        vector<int> r,c;
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {r.push_back(i);c.push_back(j);}
            }
        }
        sort(r.begin() , r.end());
        sort(c.begin() ,c.end());
        return ((r[r.size()-1] - r[0]+1)*(1+c[c.size()-1] -c[0]));

    }
};