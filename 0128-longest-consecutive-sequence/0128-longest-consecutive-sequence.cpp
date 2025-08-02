class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin() ,nums.end());
        int n =nums.size();
        if(n==0)
        {return 0;}
        if(n==1){return 1;}
        int ans = 0;
        int c =1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1 ]  == 1)
            {c++;}
            else if(nums[i]==nums[i-1])
            {continue;}
            else{
                ans= max(ans,c);
                c=1;
            }
        }
          ans= max(ans,c);
        return ans;
    }
};