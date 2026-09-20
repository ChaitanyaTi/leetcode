class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int lmax = 0;
        int rmax = 0;
        int totalw = 0;
        while(left<=right){
            if(height[left] <= height[right]){
                if(height[left]>=lmax){
                    lmax = height[left];
                }
                else{
                totalw += (lmax - height[left]);
                }
                left++;
            }
            else{
                if(height[right]>=rmax){
                    rmax = height[right];
                }
                else{
                totalw += (rmax - height[right]);
                }
                right--;
            }
        }
        return totalw;
        
    }
};