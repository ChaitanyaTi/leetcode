class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxi = INT_MIN;
        unordered_map<int,int>f;
        for(int i =0;i<nums.size(); i++){
            f[nums[i]]++;
        }
        int max_freq = 0;
        int ans = nums[0];
        for(auto it : f){
            if(it.second>max_freq){
                max_freq = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};