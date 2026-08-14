#include <string>
#include <vector>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int n = s1.length();
        int m = s2.length();

        if (n + m != s3.length()) {
            return false;
        }

        
        std::vector<bool> dp(m + 1, false);

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 && j == 0) {
                    dp[j] = true; 
                } else if (i == 0) {
                    dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
                } else if (j == 0) {
                    dp[j] = dp[j] && (s1[i - 1] == s3[i - 1]);
                } else {
                    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || 
                            (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }

        return dp[m];
    }
};