class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1len = s1.size();
        int s2len = s2.size();
        if(s1len > s2len){
            return false;
        }
        vector<int> s1hash(26,0);
        vector<int> s2hash(26,0);
        for(int i =0; i<s1len; i++){
            s1hash[s1[i] - 'a']++;
            s2hash[s2[i] - 'a']++;
        }
        int left = 0;
        for(int right = s1len-1; right < s2len; right++){
            if(s1hash == s2hash){
                return true;
            }
            if(right + 1 < s2len){
                s2hash[s2[right + 1] - 'a']++;
                s2hash[s2[left]-'a']--;
                left++;
            }
        }
        return false;
    }
};