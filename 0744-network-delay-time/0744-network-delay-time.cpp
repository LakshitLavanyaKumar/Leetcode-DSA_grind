class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
           vector<vector<pair<int,int>>> adj(n+1);
           for(auto it:times)
           {
            adj[it[0]] .push_back({it[1] , it[2]});
           }
           vector<int> dist(n+1  , INT_MAX);
           priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
           pq.push({0,k});
           dist[k] = 0;
           while(!pq.empty())
           {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
           
            for(auto it:adj[node])
            {
                if(dis+it.second<dist[it.first])
                {
                    dist[it.first] = dis+it.second;
                    pq.push({dis+it.second , it.first});
                }
            }      
           }
           int ans=0;
           for(int i =1;i<=n;i++)
           {
            if(dist[i] == INT_MAX)
            {
              return -1;  
            }
            if(ans<dist[i])
            {ans =dist[i];}
           }
           return ans;
     }
};