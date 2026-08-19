class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack <int> stk;
        vector<int> ans(n);
        for(int i = n*2-1; i>=0; i--){
            int current = nums[i % n];
            while(!stk.empty() &&  current >= stk.top()){
                stk.pop();
            }
            if(i<n){
                if(!stk.empty()){
                    ans[i] = stk.top();
                }
                else{
                    ans[i] = -1;
                }
            }
            stk.push(current);
        }
        return ans;
    }
};