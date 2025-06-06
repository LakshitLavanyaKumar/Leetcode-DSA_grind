class Solution {
public:
    const int M = 1000000007;
    long long  fact(int k)
    {
       long long  int g =1;
        for(int i =1;i<=k;i++)
            {
                g = (g*i)%M;
            }
        return g;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> adj(n+1);
        for(int i =0;i<edges.size();i++)
            {
                adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);
            }
        vector<int> vis(n+1 , 0);
        queue<pair<int,int>> q;
        q.push({1,0});
        int ans =0;
        vis[1] =1;
        while(!q.empty())
            {
                int node = q.front().first;
                int depth = q.front().second;
                q.pop();
               if(depth>ans){ans =depth;}
                for(auto it:adj[node])
                    {
                        if(!vis[it])
                        {
                            vis[it] =1;
                            q.push({it,depth+1});
                        }
                    }
            }
        cout<<ans<<endl;
        //int b = ans*2;
        //int a =ans;
         long  long int e =0;
        for(int i =1;i<=ans;i+=2)
            {
                long  long  s = (fact(ans)/fact(i))%M;
                s = (s/fact(ans-i))%M;
                e = (e+s)%M;
            }
        return (int )e%M;
    }
};