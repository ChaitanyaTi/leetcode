class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int n = nums.size();
        int end = nums.size()-1;
        int res = -1;
        while (start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > nums[n-1]){
                if(nums[mid] < target){
                    start = mid + 1;
                }
                else{
                    if(nums[0] > target){
                        start = mid + 1;
                    }
                    else{
                        end = mid-1;
                    }
                }
            }
            else{
                if(nums[mid] > target){
                    end = mid-1;
                }
                else{
                    if(nums[n-1] < target){
                        end = mid - 1;
                    }
                    else{
                        start = mid + 1;
                    }
                }
            }
        
        }
        return -1;
    }
};