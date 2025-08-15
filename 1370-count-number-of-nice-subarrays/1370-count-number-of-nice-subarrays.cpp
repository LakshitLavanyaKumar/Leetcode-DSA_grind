class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
     int atMost(vector<int>& nums, int goal){
        int head, tail = 0, sum = 0, result = 0;
        for (head = 0; head < nums.size(); head++) {
            sum += (nums[head]&1?1:0);
            while (sum > goal && tail <= head) {
                sum -= (nums[tail]&1?1:0);
                tail++;
            }
            result += head - tail + 1;
        }
        return result;
    }
};