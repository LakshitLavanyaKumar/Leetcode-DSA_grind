class Solution {
public:
const int MOD =1000000007;
    int countPaths(int n, vector<vector<int>>& roads) {
            vector<vector<pair<int,int>>> adj(n);
           for(auto it:roads)
           {
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
           }
           vector<long long int> dist(n  , LLONG_MAX);
           vector<int> ways(n  ,0);
           ways[0] = 1;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
           pq.push({0,0});
           dist[0] = 0;
           while(!pq.empty())
           {
          long long   int dis = pq.top().first;
          long long   int node = pq.top().second;
            pq.pop();
           
            for(auto it:adj[node])
            {
                
                if((long long )dis+(long long )it.second<dist[it.first])
                {
                    dist[it.first] = (long long )dis+(long long )it.second;
                    ways[it.first] =ways[node];
                    pq.push({(long long )dis+(long long )it.second, it.first});
                }
 else if((long long )dis+(long long )it.second == dist[it.first])       
          {
                    ways[it.first] = (ways[it.first]+ways[node])%MOD;
                }
            }      
           }
         return (int)ways[n-1]%MOD;
    }
};