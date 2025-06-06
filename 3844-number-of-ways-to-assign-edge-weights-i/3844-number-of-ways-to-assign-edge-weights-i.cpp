class Solution {
public:
    const int M = 1000000007;

    vector<long long> factorial, invFactorial;

    long long modpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % M;
            a = (a * a) % M;
            b >>= 1;
        }
        return res;
    }

    void precomputeFactorials(int n) {
        factorial.resize(n + 1);
        invFactorial.resize(n + 1);
        factorial[0] = 1;
        for (int i = 1; i <= n; ++i)
            factorial[i] = (factorial[i - 1] * i) % M;
        for (int i = 0; i <= n; ++i)
            invFactorial[i] = modpow(factorial[i], M - 2);
    }

    long long C(int n, int r) {
        if (r < 0 || r > n) return 0;
        return factorial[n] * invFactorial[r] % M * invFactorial[n - r] % M;
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
    precomputeFactorials(ans);

        // Sum of combinations C(maxDepth, i) for all odd i
        long long c = 0;
        for (int i = 1; i <= ans; i += 2) {
            c = (c + C(ans, i)) % M;
        }

        return (int)c;
    }
};