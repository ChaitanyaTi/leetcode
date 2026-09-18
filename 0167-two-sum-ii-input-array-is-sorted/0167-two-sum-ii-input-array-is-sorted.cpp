class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i =0;
        int j =numbers.size()-1;
        int sum = 0;
        vector<int>ans;
        while(i<j){
            sum = numbers[i] + numbers[j];
            if(target > sum){
                i++;
            }
            else if(target < sum){
                j--;
            }
            else{
                return {i+1,j+1};
            }
        }
        return {};
    }
};