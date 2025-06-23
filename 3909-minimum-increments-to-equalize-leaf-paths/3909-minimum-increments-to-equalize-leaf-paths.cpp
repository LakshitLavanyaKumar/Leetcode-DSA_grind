class Solution {
public:
    long long  f(long long  node , int n , vector<vector<long long >>& adj , vector<int>& cost ,long long  &c,vector<bool> &vis)
    {
        vis[node] = true;
        long long g = 0;
        vector<long long> childpaths;
      for(auto it:adj[node])
          {
              if(vis[it] ==false)
              {
             long long  childPath = f(it, n, adj, cost, c, vis);
               g = max(g, childPath);
                childpaths.push_back(childPath);
              }
          }
         for(auto path : childpaths)
        {
            if(path < g)
                c++;
        }

        

        return g + cost[node];
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<long long >> adj(n);
        for(int i=0;i<edges.size();i++)
            {
                adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);
            }
        vector<bool> vis(n,false); 
        long long c =0;
        long long  d = f(0 , n , adj , cost ,c ,vis);
        return (int)c;
    }
};