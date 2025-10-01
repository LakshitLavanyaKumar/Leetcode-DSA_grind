class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int > pm(n) ,sm(n);
        pm[0] =height[0];
        sm[n-1] = height[n-1];
        for(int i =1;i<n;i++)
        {
            pm[i] = max(pm[i-1] , height[i]);

        }
               for(int i =n-2;i>=0;i--)
        {
            sm[i] = max(sm[i+1] , height[i]);

        }
        int ans =0;
        for(int i =0;i<n;i++)
        {
            if(height[i]<=pm[i] && height[i]<=sm[i])
            {
                ans+= (min(pm[i] , sm[i]) - height[i]);
            }
        }
        return ans;
    }
};