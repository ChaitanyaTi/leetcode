class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minsum = nums[0];
        int maxsum = nums[0];
        int maxi = nums[0];
        int mini = nums[0];
        for(int i =1; i<nums.size(); i++){
            maxsum = max(nums[i],maxsum+nums[i]);
            maxi = max(maxi,maxsum);
            minsum = min(nums[i], minsum+nums[i]);
            mini = min(mini,minsum);
            
        }
        return max(abs(maxi), abs(mini));
    }
};