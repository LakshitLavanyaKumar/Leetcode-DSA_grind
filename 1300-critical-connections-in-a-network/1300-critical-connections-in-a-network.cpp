class Solution {
   // private:
    int timer = 1;
  
    void dfs(int node  , int parent , vector<int> &vis, vector<vector<int>> &adj,
    int tin[] ,int low[] ,vector<vector<int>> &bridges)
    {
       vis[node] =1;
       tin[node] = low[node] = timer;timer++;
       for(auto child:adj[node])
       {
        if(child==parent)
        {continue;}
        if(vis[child]==0)
        {
            dfs(child,node,vis,adj,tin,low,bridges);
            low[node] = min(low[child],low[node]);
            if(tin[node]<low[child])
            {bridges.push_back({node,child});}
        }
        else{
           low[node] = min(low[node] , low[child]);
        }
       }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0,-1,vis,adj,tin,low,bridges);
        return bridges;
    }
};