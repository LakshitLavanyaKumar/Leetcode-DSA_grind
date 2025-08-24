class DisjointSet
{
    vector<int> parent , size,rank;
    public:
    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n);
        rank.resize(n);
        for(int i =0;i<n;i++)
        {
            parent[i] =i;
        }
    }
    int findUPar(int node)
    {
        if(node == parent[node]){return node;}

        return parent[node] = findUPar(parent[node]);
    }

    void UnionByRank(int u, int v)
    {
      int pu = findUPar(u);
      int pv = findUPar(v);
      if(pu == pv)
      {return ;}
      if(rank[pu]>rank[pv])
      {
         parent[pv] = pu;
      }
      else if(rank[pv]>rank[pu])
      {
        parent[pu] = pv;
      }
      else{
        parent[pu] = pv;
        rank[pv]++;
      }
    }

    void UnionBySize(int u,int v)
    {
        int pu = findUPar(u);
      int pv = findUPar(v);
      if(pu == pv)
      {return ;}
      if(size[pu]>size[pv])
      {
         parent[pv] = pu;
         size[pu]+=size[pv];
      }
      else if(size[pv]>size[pu])
      {
        parent[pu] = pv;
      size[pv]+=size[pu];
      }
      else{
        parent[pu] = pv;
        size[pv]+=size[pu];
      }
    }
};

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n =nums.size();
        DisjointSet dsu(n);
        stack<int> st;
        for(int i =0;i<n;i++)
        {
            int prev =i;
            if(!st.empty()){prev = st.top();}
            while(!st.empty() && nums[i]<nums[st.top()])
            {
                dsu.UnionByRank(i ,st.top() );
                st.pop();
            }

            if(nums[i]>nums[prev]){st.push(i);}
            else{st.push(prev);}
        }
 

 stack<int> st1;
        for(int i =n-1;i>=0;i--)
        {
            int prev =i;
            if(!st1.empty()){prev = st1.top();}
            while(!st1.empty() && nums[i]>nums[st1.top()])
            {
                dsu.UnionByRank(i ,st1.top());
                st1.pop();
            }

            if(nums[i]<nums[prev]){st1.push(i);}
            else{st1.push(prev);}
        }
vector<int> c(n ,INT_MIN );
        for(int i=0;i<n;i++)
        {
              int x = dsu.findUPar(i);
              c[x] =max(c[x]  , nums[i] );
        }
        vector<int> ans(n);
        for(int  i=0;i<n;i++)
        {
            ans[i] = c[dsu.findUPar(i)];
        }
        return ans;
    }
};