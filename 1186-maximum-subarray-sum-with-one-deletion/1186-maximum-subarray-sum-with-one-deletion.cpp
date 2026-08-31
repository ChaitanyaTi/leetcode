class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodel = arr[0];
        int onedel = 0;
        int res = arr[0];
        for(int i =1; i<arr.size(); i++){
            int prevnodel = nodel;
            nodel = max(arr[i], nodel+arr[i]);
            onedel = max(prevnodel, onedel+arr[i]);
            res = max(res,max(nodel,onedel));
        }
        return res;
    }
};