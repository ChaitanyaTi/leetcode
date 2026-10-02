class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = nums[0];
        int minsum = nums[0];
        int maxsum = nums[0];
        int maxi = nums[0];
        int mini = nums[0];
        for(int i =1; i<nums.size(); i++){
            maxsum = max(nums[i],maxsum+nums[i]);
            maxi = max(maxi,maxsum);
            minsum = min(nums[i], minsum+nums[i]);
            mini = min(mini,minsum);
            total_sum += nums[i];
        }
        if (maxsum < 0) {
            return maxi;
        }
        return max(maxi, total_sum - mini);
    }
};