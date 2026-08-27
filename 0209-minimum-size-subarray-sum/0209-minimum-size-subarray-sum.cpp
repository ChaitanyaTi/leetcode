class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int sum = 0;
        int minlen = INT_MAX;
        int left = 0;
        for(int right =0; right<arr.size(); right++){
            sum = sum + arr[right];
            while(sum>=target){
                int sublen = right - left + 1;
                minlen = min(minlen, sublen);
                sum = sum - arr[left];
                left++;
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};