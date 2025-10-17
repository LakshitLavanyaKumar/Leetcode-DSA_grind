class Solution {
public:
#define ll long long
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin() , envelopes.end(), [](const vector<int>&a , const vector<int>&b){
            if(a[0] == b[0])
            {return a[1]>b[1];}
return a[0]<b[0];
        });
      vector<int> v;
      for(ll i =0;i<n;i++)
      {
        v.push_back(envelopes[i][1]);
      }
      vector<int> temp;
      temp.push_back(v[0]);
      for(ll i=1;i<n;i++)
      {
        ll in = lower_bound(temp.begin() , temp.end() , v[i]) -temp.begin();
        if(in==temp.size())
        {temp.push_back(v[i]);}
        else{
            temp[in] =v[i];
        }
      }
        return (int)temp.size();
    }
};