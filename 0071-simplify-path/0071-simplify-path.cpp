#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> st;
        std::stringstream ss(path);
        std::string token;

        // Split path by delimiter '/'
        while (std::getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {                
                st.push_back(token);
            }
        }

        if (st.empty()) {
            return "/";
        }

        std::string result = "";
        for (const std::string& dir : st) {
            result += "/" + dir;
        }

        return result;
    }
};