class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9+7;
        int n =arr.size();
        vector<int> pse(n),nse(n);
        stack<int> st1,st2;
        for(int i =0;i<n;i++)
        {
            while(!st1.empty() && arr[st1.top()]>=arr[i])
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
            while(!st2.empty() && arr[st2.top()]>arr[i])
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
       long long  int ans =0;
        for(int i =0;i<n;i++)
        {
             long long left = i - pse[i];
            long long right = nse[i] - i;
            long long contrib = ( (long long)arr[i] * left ) % MOD;
            contrib = (contrib * right) % MOD;
            ans = (ans+contrib)%MOD;
        }
        return (int)ans%MOD;
    }
};