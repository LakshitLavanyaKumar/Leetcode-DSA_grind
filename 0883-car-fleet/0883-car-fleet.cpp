   #include<bits/stdc++.h>
using namespace std;
#define ll int
class Solution {
 
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
         ll n,m;
        n = position.size();
        m = target;

        vector<pair<ll,ll>> vp(n);
        vector<ll> p = position;

                vector<ll> s = speed;

        for(ll i=0;i<n;i++)
        {
            vp[i] = { p[i] , s[i] };
        }
        sort(vp.rbegin() , vp.rend() );
        vector<double> f;
        for(ll i=0;i<n;i++)
        {
            double g = double(m-vp[i].first) /(double)vp[i].second; 
            f.push_back(g);
        }
        vector<double> prefm(n);
        prefm[0] =f[0];
        for(ll i=1;i<n;i++)
        {
            prefm[i] = max(prefm[i-1] , f[i]);
        }
        //     for(auto it:f)
        // {cout<<it<<" ";}
        // cout<<endl;
        // for(auto it:prefm)
        // {cout<<it<<" ";}
        // cout<<endl;
        set<double> st(prefm.begin() , prefm.end());
       return  st.size(); 
    }
};