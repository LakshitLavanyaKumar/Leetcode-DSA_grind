class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n =s.length();
        long long int nasf =0;
       // int ans =0;
        long long tot = (1LL *n *(n+1))/2;
        if(k>tot)return -1;
       int l =0;
        int r =n-1;
        int ans = INT_MAX;;
        while(l<=r)
            {
                int mid = (l+r)/2;
                vector<int> v;
                 for(int i =0;i<=mid;i++)
                     {
                         v.push_back(order[i]);
                     }
                sort(v.begin() ,v.end());
                int sz=v.size();
                long long inv = 0;
                inv+= (1LL *(v[0]+1)*v[0] )/ 2;
                for(int i =0;i<v.size()-1;i++)
                    {
                        long long l = v[i+1] - v[i]-1;
                        inv += (1LL * l*(l+1))/2;
                    }
                inv+= (1LL * (n-v[sz-1]-1)*(n-v[sz-1]) )/ 2;
                // if(v[0]!=0 && v.size()>1)
                // {
                //  int l = v[1] -1;
                //         inv += (1LL * l*(l+l))/2;
                // }
                // if(v[mid]!=n-1)
                // {
                //  int l = n -v[mid];
                //         inv += (1LL * l*(l+l))/2;
                // }
             //   inv =sum;
                cout<<inv<<endl;
                if(tot-inv >=k){ r = mid-1;ans = min(ans,mid);}
                else{
                 l= mid+1;
                }
            }
      if(ans==INT_MAX){return -1;}
        return ans;
    }
};