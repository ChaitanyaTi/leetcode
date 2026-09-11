class Solution {
public:
    int maxar(vector<int> piles){
        int maxi = INT_MIN;
        for(int i =0; i<piles.size(); i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    long long fun(vector<int> piles,int n,int speed){
        long long hr = 0;
        for(int i =0 ; i<n; i++){
            hr += piles[i]/speed;
            if(piles[i]%speed != 0){
                hr++;
            }
        }
        return hr;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int n = piles.size();
        int res = -1;
        int end = maxar(piles);
        while(start <= end){
            int mid = start + (end-start)/2;
            long long hour = fun(piles,n,mid);
            if(hour > h){
                start = mid+1;
            }
            else{
                res = mid;
                end = mid - 1;
            }
        }
        return res;
    }
};