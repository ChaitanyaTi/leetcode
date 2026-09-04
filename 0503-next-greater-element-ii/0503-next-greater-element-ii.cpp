class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;
        for(int i= n*2-1; i>=0; i--){
            int current = nums[i%n];
            while(!st.empty() && current >= st.top()){
                st.pop();
            }
            if(i<n){
                if(!st.empty()){
                    res[i] = st.top();
                }
                else{
                    res[i] = -1;
                }
            }
            st.push(current);
        }
        return res;
    }
};