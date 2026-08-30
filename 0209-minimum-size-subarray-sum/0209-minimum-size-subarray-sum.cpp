class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int right =0;
        int left =0;
        int sum =0;
        int mini = INT_MAX;
        for(int right =0; right<nums.size(); right++){
            sum = sum + nums[right];
            while (sum >= target){
                int len = right - left + 1;
                mini = min(mini, len);
                sum = sum - nums[left];
                left++;
            }
        }
        return mini == INT_MAX? 0:mini;
    }
};