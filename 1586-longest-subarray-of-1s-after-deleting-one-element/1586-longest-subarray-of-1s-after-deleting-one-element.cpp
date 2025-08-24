class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        int r =0,l=0;;
        int ans =0;
        while(r<n)
        {
            mp[nums[r]]++;
            while(l<r && mp[0]>1)
            {mp[nums[l]]--;
                l++;
                
            }
            ans =max(r-l+1,ans);
            r++;
        }

        return ans-1;
    }
};