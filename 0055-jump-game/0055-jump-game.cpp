class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int in =n-1;
        int l =n-2;
        while(l>=0 )
        {
            if( nums[l]>=(in-l) )
            {
              in =l;
            }
            l--;
        }
        return in==0;
    }
};