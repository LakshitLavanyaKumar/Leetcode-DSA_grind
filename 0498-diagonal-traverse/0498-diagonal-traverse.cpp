class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int k = m+n-1;
        vector<vector<int>> adj(k);
        for(int i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                int h = i+j;
                adj[h].push_back(mat[i][j]);
            }
        }
vector<int> ans;
int b =0;
for(auto it:adj)
{
    vector<int> v =it;
if(!(b&1))
{
for(int i =v.size()-1;i>=0;i--)
{ans.push_back(v[i]);}

}
else{
    for(int i =0;i<v.size();i++)
{ans.push_back(v[i]);}
}
b++;
}
return ans;
    }
};