#include <vector>

class Solution {
public:
    void backtrack(int index, std::vector<int>& nums, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }
        
        current.push_back(nums[index]);
        backtrack(index + 1, nums, current, result);
        
        current.pop_back();
        
        backtrack(index + 1, nums, current, result);
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
};