class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int closesum = nums[0] + nums[1] + nums[2];
    for(int i =0; i<nums.size()-2; i++){
        int left = i+1;
        int right = nums.size()-1;
        while(left<right){
            int currentsum = nums[i]+nums[left]+nums[right];
            if(abs(currentsum - target) < abs(closesum - target)){
                closesum = currentsum;
            }
            else if(currentsum > target){
                right--;
            }
            else if(currentsum < target){
                left++;
            }
            else{
                return currentsum;
            }
        }
    }
    return closesum;
    }
};