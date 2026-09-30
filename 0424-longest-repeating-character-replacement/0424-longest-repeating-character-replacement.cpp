class Solution {
public:
    int maxi(vector<int>&f){
        int maxy = INT_MIN;
        for(int i =0; i<256 ; i++){
            maxy = max(maxy,f[i]);
        }
        return maxy;
    }
    int characterReplacement(string s, int k) {
        vector<int>f(256,0);
        int maxy = INT_MIN;
        int left = 0;
        for(int right =0; right< s.size(); right++){
            f[s[right]]++;
            int len = right - left + 1;
            int maxier = maxi(f);
            int diff = len - maxier;
            while(diff > k){
                f[s[left]]--;
                left++;
                maxier = maxi(f);
                int len = right - left + 1;
                diff = len - maxier;
            }
            len = right - left + 1;
            maxy = max(maxy, len);
        }
        return maxy;
    }
};