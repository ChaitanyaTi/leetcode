class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        vector<int>ans;
        while (s<=e){
            if(abs(nums[s]) > abs(nums[e])){
                long long pro = nums[s]*nums[s];
                ans.push_back(pro);
                s++;
            }
            else{
                long long proe = nums[e]*nums[e];
                ans.push_back(proe);
                e--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};