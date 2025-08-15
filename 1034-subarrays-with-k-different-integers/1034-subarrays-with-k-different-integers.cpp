class Solution {
public:
     int atMost(vector<int>& nums, int goal){
        map<int,int> mp;
        int head, tail = 0, sum = 0, result = 0;
        for (head = 0; head < nums.size(); head++) {
            mp[nums[head]]++;;
            while (mp.size() > goal && tail < head) {
                mp[nums[tail]]--;
                if(mp[nums[tail]] == 0)
                {mp.erase(mp.find(nums[tail]));}
                tail++;
            }
            if(mp.size()<=goal)
            {
            result += head - tail + 1;
        }
        }
        return result;
     }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n   =  nums.size();
        return atMost(nums, k) - atMost(nums, k-1);
    }
};