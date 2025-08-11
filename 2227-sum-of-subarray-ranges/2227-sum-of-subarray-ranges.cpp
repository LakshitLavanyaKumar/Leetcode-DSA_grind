#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
         int MOD = 1e9+7;
         vector<int> arr=nums;
        int n =arr.size();
        vector<int> pse(n),nse(n),pge(n),nge(n);
        stack<int> st1,st2;
        for(int i =0;i<n;i++)
        {
            while(!st1.empty() && arr[st1.top()]>arr[i])
            {
                nse[st1.top()] = i;
                st1.pop();
            }
            // if(!st1.empty())
            // {
            // nse[st1.top()] = i;
            //     }
            st1.push(i);
        } while(!st1.empty() )
            {
                nse[st1.top()] = n;
                st1.pop();
            }
        for(auto it:nse)
        {cout<<it<<" ";}
        cout<<endl;

         for(int i =n-1;i>=0;i--)
        {
            while(!st2.empty() && arr[st2.top()]>=arr[i])
            {
                pse[st2.top()] = i;
                st2.pop();
            }
            // if(!st1.empty())
            // {
            // nse[st1.top()] = i;
            //     }
            st2.push(i);
        } while(!st2.empty() )
            {
                pse[st2.top()] = -1;
                st2.pop();
            }
        for(auto it:pse)
        {cout<<it<<" ";}
        cout<<endl;
        ////
        stack<int> st3,st4;
        for(int i =0;i<n;i++)
        {
            while(!st3.empty() && arr[st3.top()]<arr[i])
            {
                nge[st3.top()] = i;
                st3.pop();
            }
            // if(!st1.empty())
            // {
            // nse[st1.top()] = i;
            //     }
            st3.push(i);
        } while(!st3.empty() )
            {
                nge[st3.top()] = n;
                st3.pop();
            }
        for(auto it:nge)
        {cout<<it<<" ";}
        cout<<endl;

         for(int i =n-1;i>=0;i--)
        {
            while(!st4.empty() && arr[st4.top()]<=arr[i])
            {
                pge[st4.top()] = i;
                st4.pop();
            }
            // if(!st1.empty())
            // {
            // nse[st1.top()] = i;
            //     }
            st4.push(i);
        } while(!st4.empty() )
            {
                pge[st4.top()] = -1;
                st4.pop();
            }
        for(auto it:pge)
        {cout<<it<<" ";}
        cout<<endl;        
       long long  int ans =0;
        for(int i =0;i<n;i++)
        {
             long long left = i - pse[i];
            long long right = nse[i] - i;
            long long contrib = ( (long long)arr[i] * left );
            contrib = (contrib * right);
            ans = (ans+contrib);
        }
         long long  int ans1 =0;
        for(int i =0;i<n;i++)
        {
             long long left = i - pge[i];
            long long right = nge[i] - i;
            long long contrib = ( (long long)arr[i] * left ) ;
            contrib = (contrib * right);
            ans1 = (ans1+contrib);
        }
        long long int ans2 = ans1-ans;
        return ans2;
       
    }
};