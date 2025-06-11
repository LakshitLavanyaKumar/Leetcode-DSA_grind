class Solution {
public:
	int findUPar(int node,vector<int>& parent,vector<int>& rank)
{
  if(node == parent[node])
  {return node;}

  return parent[node] = findUPar(parent[node],parent,rank);
}
void unionByRank(int u ,int v,vector<int>& parent,vector<int>& rank)
{
  int ultP_u = findUPar(u,parent,rank);
  int ultP_v = findUPar(v,parent,rank);
  if(ultP_u == ultP_v)
  {return;}
  if(rank[ultP_u] < rank[ultP_v])
  {
    parent[ultP_u]  = ultP_v;
  }
  else if(rank[ultP_v] < rank[ultP_u])
  {
       parent[ultP_v]  = ultP_u;
  }
  else
  {
     parent[ultP_v]  = ultP_u;
     rank[ultP_u]++;
  }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
          
          vector<int> rank ,parent,size;


  rank.resize(n , 0);//for 1 or 0 both based indexing;
  parent.resize(n);
   size.resize(n );

  for(int i=0;i<n;i++)
  {parent[i] = i;}
    
    int c=0;
    for(int i=0;i<connections.size();i++)
    {
       int u = connections[i][0];
       int v = connections[i][1];
      
       if(findUPar(u,parent,rank) == findUPar(v,parent,rank))
       {
        c++;//ye toh extra hai
       } 
       else
       {
       unionByRank(u,v,parent,rank);//necesaary  connjection
    }
    }
    if(connections.size() < n-1 )
    {return -1;}
    set<int> d;
    int o=0;
    for(int i=0;i<n;i++)
    {if(parent[i]==i)o++;}
    int k =d.size();
    int req = k-1;
    for(auto it:parent)
    {cout<<it<<" ";}
    cout<<endl;
    cout<<c<<" "<<req<<endl;
if(o-1 <= c)
{return o-1;}
return -1;
    //
    //int s = connections.size();
    }
};