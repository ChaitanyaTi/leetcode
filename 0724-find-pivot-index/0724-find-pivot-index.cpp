class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        int left =0;
        for(int i=0; i<nums.size(); i++){
            int right = sum-left-nums[i];
            if(right == left){
                return i;
            }
            else{
                left += nums[i];
            }
        }
        return -1;
    }
};