#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLength = words[i].length();
            int j = i + 1;

            while (j < n && lineLength + 1 + (int)words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }

            int numWords = j - i;
            std::string line = "";

            if (j == n || numWords == 1) {
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        line += " ";
                    }
                }
                
                line.append(maxWidth - line.length(), ' ');
            } 
            else {
                int totalWordChars = 0;
                for (int k = i; k < j; ++k) {
                    totalWordChars += words[k].length();
                }

                int totalSpaces = maxWidth - totalWordChars;
                int gaps = numWords - 1;
                int baseSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        int spacesToAdd = baseSpaces + (k - i < extraSpaces ? 1 : 0);
                        line.append(spacesToAdd, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j; 
        }

        return result;
    }
};