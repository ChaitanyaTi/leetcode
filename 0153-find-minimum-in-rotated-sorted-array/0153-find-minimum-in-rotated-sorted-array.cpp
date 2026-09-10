class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int n = nums.size();
        int end = nums.size()-1;
        int res = -1;
        while (start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] > nums[n-1]){
                start = mid + 1;
            }
            else {
                res = mid;
                end = mid - 1;
            }
        }
        return nums[res];
    }
};