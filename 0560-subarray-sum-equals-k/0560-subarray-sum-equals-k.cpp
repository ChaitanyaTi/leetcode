#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        unordered_map<int,int>f;
        int sum =0;
        int res = 0;
        f[0] = 1;
        for(int i =0; i<nums.size(); i++){
            sum += nums[i];
            int ques = sum - k;
            if(f.find(ques) != f.end()){
                res += f[ques];
            }
            f[sum]++;
        }
        return res;
    }
};