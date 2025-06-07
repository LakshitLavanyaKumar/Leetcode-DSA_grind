class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<int,int>> pq;
        set<int> indices;
     int n = s.length();
     for(int i =0;i<n;i++)
     {
        if(s[i]!='*')
        {
            int a = 25 - (s[i] - 'a');
            int b = i;
            pq.push({a,b});

        }
        else if(s[i]=='*')
        {
             indices.insert(i);
             if(pq.size()>0 )
             {
                int p = pq.top().second;
                indices.insert(p);
                pq.pop();
             }
        }
     }
     string ans="";
     for(int i =0;i<n;i++)
     {
        if(indices.find(i)!=indices.end())
        {continue;}
        ans+=s[i];
     }
     return ans;
    }
};