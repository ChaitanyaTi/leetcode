class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>f;
        f[0] = -1;
        int prefixsum = 0;
        int maxlen = 0;
        for(int i =0; i<nums.size(); i++){
            prefixsum += (nums[i]==0)?-1:1;
            if(f.find(prefixsum) != f.end()){
                maxlen=max(maxlen,i-f[prefixsum]);
            }
            else{
                f[prefixsum]=i;
            }
        }
        return maxlen;
    }
};