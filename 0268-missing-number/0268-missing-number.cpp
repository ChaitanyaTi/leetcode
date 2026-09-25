class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start = 0;
        while(start < nums.size()){
            if(nums[start] != start){
                return start;
            }
            else{
                start++;
            }
        }
        return nums.size();;
    }
};