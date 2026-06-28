class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_ptr = 0, t_ptr = 0;
        
        while (s_ptr < s.length() && t_ptr < t.length()) {
            if (s[s_ptr] == t[t_ptr]) {
                s_ptr++; // Move s pointer if a match is found
            }
            t_ptr++; // Always move t pointer
        }
        
        return s_ptr == s.length();
    }
};