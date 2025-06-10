class Solution {
    #include <iostream>
#include <queue>
#include <tuple>

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int  i =0;i<flights.size();i++)
        {
           adj[flights[i][0]].push_back({flights[i][1] , flights[i][2]});

        }
       priority_queue<tuple<int, int, int>,vector<tuple<int, int, int>>,greater<tuple<int, int, int>>> pq;  
       int j =0;   
       pq.push({0,src ,0});
       vector<int> dist(n,INT_MAX);
       dist[src] =0;
       while(!pq.empty())
       {
        auto [kb ,node ,dis] = pq.top();
        cout<<node<<" "<<kb<<endl;
        // int dis = get<0>(tuple);
        // int kb = get<1>(tuple);
        // int node = get<2>(tuple);
        pq.pop();
     
            if (kb> k) continue;
        for(auto it:adj[node])
        {
            if(dis + it.second < dist[it.first])
            {
                if(kb<=k)
                {
                pq.push({kb+1 ,it.first ,dis + it.second });
                dist[it.first] = dis+it.second;
                }
               
            }

        }
       }                                      
 if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};