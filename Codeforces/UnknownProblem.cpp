#include<bits/stdc++.h>
#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
#define ll long long int
#define py cout<<"Yes"<<endl
#define pn cout<<"No"<<endl
#define M 100000000000000000
#define all(x) (x).begin(), (x).end()
#define pb push_back
/////
//to print my answer upto k decimal places
//cout << fixed << setprecision(6) << fans<<endl;; 
 
////
//////////modulo duvision ka code/////
// ll power(ll x, ll y, ll p)
// {
//     ll res = 1;
//     x = x % p;
    
//     while (y > 0)
//     {
//         if (y & 1)
//             res = (res * x) % p;
//         y = y >> 1;
//         x = (x * x) % p;
//     }
//     return res;
// }
 
// class DisjointSet{
//   vector<ll> rank ,parent,size;
//   public: 
// DisjointSet(int n)
// {
//   rank.resize(n+1 , 0);//for 1 or 0 both based indexing;
//   parent.resize(n+1);
//    size.resize(n+1 );
//   for(ll i=0;i<=n;i++)
//   {parent[i] = i;}
// }
// ll findUPar(ll node)
// {
//   if(node == parent[node])
//   {return node;}
 
//   return parent[node] = findUPar(parent[node]);
// }
// void unionByRank(ll u ,ll v)
// {
//   ll ultP_u = findUPar(u);
//   ll ultP_v = findUPar(v);
//   if(ultP_u == ultP_v)
//   {return;}
//   if(rank[ultP_u] < rank[ultP_v])
//   {
//     parent[ultP_u]  = ultP_v;
//   }
//   else if(rank[ultP_v] < rank[ultP_u])
//   {
//        parent[ultP_v]  = ultP_u;
//   }
//   else
//   {
//      parent[ultP_v]  = ultP_u;
//      rank[ultP_u]++;
//   }
 
// }
// void unionBySize(ll u ,ll v)
// {
//   ll ultP_u = findUPar(u);
//   ll ultP_v = findUPar(v);
//   if(ultP_u == ultP_v)
//   {return;}
//   if(size[ultP_v] > size[ultP_u])
//   {
//     parent[ultP_v] = ultP_u;
//     size[ultP_v]+=size[ultP_u];
//   } 
//   else{
//       parent[ultP_u] = ultP_v;
//     size[ultP_u]+=size[ultP_v];
//   }
// }
//   void printp()
//   {
// for(auto it:parent)
// {cout<<it<<" "<<endl;}
//   }
 
// };
 
 
//     void dfs(ll node , ll col , vector<ll> adj[],vector<bool>& vis ,vector<ll>& color  )
//     {
//      color[node] = col;
//      vis[node] = true;
//      for(auto child:adj[node])
//      {
//         if(!vis[child])
//         {
//           dfs(child ,!col,adj,vis,color);
//         }
//      }   
//     }
//   // void f(ll N,map<ll,ll> & mp)
//   // {
 
  
// ll cnt(ll num)
// {
//     return num * (num+1)  /2;
// }
//     void dfs(ll node, ll vis[], stack<ll> &st,vector<vector<ll>> &adj) {
//         vis[node] = 1;
//         for (ll it = 0; it < adj[node].size(); it++) {
//             if (adj[node][it] == 1 && !vis[it]) {
//                 dfs(it, vis, st, adj);
//             }
//         }
//         st.push(node);
//     }
//     vector<ll> tS(ll n, vector<vector<ll>> &adj) {
//         ll vis[n] = {0};
//         stack<ll> st;
//         for (ll i = 0; i < n; i++) {
//             if (!vis[i]) {
//                 dfs(i, vis, st, adj);
//             }
//         }
 
// //         vector<ll> ans;
// //         while (!st.empty()) {
// //             ans.push_back(st.top());
// //             st.pop();
// //         }
// //       //  reverse(ans.begin() , ans.end());
// //         return ans;
// //     }
 
// // void dp(ll ind,vector<ll>& v,ll sum,vector<ll> ans,vector<ll>& r)
// // {
// //     if(sum==0)
// //     {if(ans.size()==3){r=ans;return;}}
// //     if(ind<0 || sum<0)return ;
// //     //take case
// //     ans.push_back(ind);
// //     dp(ind-1,v,sum-v[ind],ans,r);
// //     ans.pop_back();
// //     //not take
// //     dp(ind-1,v,sum,ans,r);  
// // }
// // n is atill latgr for dp 
// ll maxSubarraySum(vector<ll> &arr) {
//     ll res = arr[0];
//     ll maxEnding = arr[0];
 
//     for (ll i = 1; i < arr.size(); i++) {
      
//         // Find the maximum sum ending at index i by either extending 
//         // the maximum sum subarray ending at index i - 1 or by
//         // starting a new subarray from index i
//         maxEnding = max(maxEnding + arr[i], arr[i]);
      
//         // Update res if maximum subarray sum ending at index i > res
//         res = max(res, maxEnding);
//     }
//     return res;
// }
// void primeFactors(ll n,map<ll,ll>& mp) {
//     // Count the power of 2
//    ll count = 0;
//     if(n<=1){return ;}
    
//     while (n % 2 == 0) {
//         count++;
//         n /= 2;
//     }
//     if (count > 0)
//         {mp[2] = count;}
 
//     // Check for odd prime factors
//     for (ll i = 3; i * i <= n; i += 2) {
//         count = 0;
//         while (n % i == 0) {
//             count++;
//             n /= i;
//         }
//         if (count > 0)
//             {mp[i] = count;}
//     }
 
//     // If n is still greater than 2, it must be a prime number
//     if (n > 2)
//         {mp[1] = count;}
// }
// vector<pair<ll, ll>> primeFactorization(ll x, vector<ll>& spf) {
//     vector<pair<ll, ll>> ans;
//     while (x != 1) {
//         ll prime = spf[x];
//         ll cnt = 0;
//         while (x % prime == 0) {
//             cnt++;
//             x = x / prime;
//         }
//         ans.push_back({prime, cnt});
//     }
//     return ans;
// }
// bool isPrime(ll n) {
//     if (n <= 1) return false;
//     if (n <= 3) return true;
//     if (n % 2 == 0 || n % 3 == 0) return false;
//     for (ll i = 5; i * i <= n; i += 6) {
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     }
//     return true;
// }
// bool mex(vector<ll> arr, ll N,ll &mid, ll k)
// {
//     ll count = 0;
//     unordered_map<ll, ll> freq;
//     unordered_set<ll> seen;
//     ll missing = mid;
 
//     for (ll i = 0; i < arr.size(); ++i) {
//         if (arr[i] < mid && seen.find(arr[i]) == seen.end()) {
//             seen.insert(arr[i]);
//             missing--;
//         }
 
//         if (missing == 0) {
//             count++;
//             seen.clear();
//             missing = mid;
//         }
//     }
 
//     return count >= k;
 
// }
 
 
 
// bool is_subseq(vector<ll> &a, vector<ll> &b) {
//     ll i = 0, j = 0;
//     while (i < a.size() && j < b.size()) {
//         if (a[i] == b[j]) j++;
//         i++;
//     }
//     return j == b.size();
// }
 
// bool check(vector<ll> &a, vector<ll> &b, ll x) {
//     ll m = b.size();
//     for (ll i = 0; i <= m; i++) {
//         vector<ll> b_copy = b;
//         b_copy.insert(b_copy.begin() + i, x);
//         if (is_subseq(a, b_copy)) return true;
//     }
//     return false;
// }
// bool can(vector<ll> &a, vector<ll> &b) {
//     return is_subseq(a, b);
// }
// void dfs(vector<ll> &ans,ll node,vector<vector<ll>> &adj,ll n,vector<bool> &vis,ll &c)
// {
//    vis[node] = true;
//    c++;
//     // ans[node] = c;
//    for(auto it:adj[node])
//    if(!vis[it])
//    {
//      dfs(ans, it,adj,n,vis,c);
//    }
 
   
// }
bool isSubset(const std::set<ll>& x, const std::set<ll>& y) {
    for (ll elem : x) {
        if (y.find(elem) == y.end()) return false;
    }
    return true;
}
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0);
/////extreme focus
//mistakes
//1. use (LL) as (1LL ) <<n;...when dealing with ll
//2. question ka logic sahi lag rha hai..par wrong ans on tt>1 to read question multiple times...chamkega
 
 ll t;
    cin>>t;
    while(t--){
ll n;
cin>>n;
vector<ll > a(n), b(n);
map<ll,ll > mp;
for(ll i=0;i<n;i++)
{cin>>a[i];mp[a[i]]++;}
for(ll i=0;i<n;i++)
{cin>>b[i];mp[b[i]]++;}
//map<ll, ll> mp;
ll ans =-1;;
vector<bool> seen(n+1);
if(a[n-1] == b[n-1])
{cout<<n<<endl;continue;}
for(ll i =n-2;i>=0;i--)
{
   
    if(a[i]==b[i] || a[i]==a[i+1] || b[i]==b[i+1] || seen[a[i]] || seen[b[i]] ){ans =i;break;}
     seen[a[i+1]] =true;seen[b[i+1]]=true;
}
cout<<ans+1<<endl;
 
    }
    return 0;
}
 
 
 
// #include <bits/stdc++.h>
// using namespace std;
 
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int t;
//     cin >> t;
    
//     while (t--) {
//        ll n;
//         cin >> n;
// vector<ll> v(n);
// map<ll,ll> mp;
// for(ll i=0;i<n;i++)
// {cin>>v[i];mp[v[i]]++;}
// ll ans =LLONG_MAX;
// for(auto it:mp)
// {ans =min(ans,it.second);}
// cout<<ans+1<<endl;
 
 
//     }
 
//     return 0;
// }