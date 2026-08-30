class Solution {
public:
    int findmax(vector<int> &a){
        int maxc = -1;
        for(int i =0; i<256; i++){
            maxc = max(maxc , a[i]);
        }
        return maxc;
    }
    int characterReplacement(string s, int k) {
        int left =0;
        int right =0;
        vector<int> f(256,0);
        int maxi = INT_MIN;
        for(int right=0; right<s.size(); right++){
            f[s[right]]++;
            int maxcnt = findmax(f);
            int len = right - left + 1;
            int diff = len - maxcnt;
            while(diff > k){
                f[s[left]]--;
                left++;
                maxcnt = findmax(f);
                len = right - left + 1;
                diff = len - maxcnt;
            }
            len = right - left + 1;
            maxi = max(maxi, len);
        }
        return maxi;
    }
    
};