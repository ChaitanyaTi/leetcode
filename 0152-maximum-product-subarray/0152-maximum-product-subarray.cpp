class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpro = nums[0];
        int minpro = nums[0];
        int result = nums[0];
        for(int i =1; i<nums.size(); i++){
            int v = nums[i];
            int v2 = minpro * v;
            int v3 = maxpro * v;
            maxpro = max(v, max(v2,v3));
            minpro = min(v, min(v2,v3));
            result = max(result,maxpro);
        }
        return result;
    }
};