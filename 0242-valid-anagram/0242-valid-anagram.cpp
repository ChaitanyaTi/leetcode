class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int count[256] ={0};
        for(int i =0; i<s.size(); i++){
            count[s[i]]++;
            count[t[i]]--;
        }
        for( int c :count ){
            if(c!=0) return false;
        }
        return true;
    }
};