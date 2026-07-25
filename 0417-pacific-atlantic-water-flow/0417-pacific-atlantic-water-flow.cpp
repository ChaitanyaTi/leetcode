#include <vector>

class Solution {
private:
    int rows, cols;
    const std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(int r, int c, std::vector<std::vector<bool>>& reachable, const std::vector<std::vector<int>>& heights) {
        reachable[r][c] = true;

        for (const auto& [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !reachable[nr][nc]) {
                if (heights[nr][nc] >= heights[r][c]) {
                    dfs(nr, nc, reachable, heights);
                }
            }
        }
    }

public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        std::vector<std::vector<bool>> pacific(rows, std::vector<bool>(cols, false));
        std::vector<std::vector<bool>> atlantic(rows, std::vector<bool>(cols, false));

        for (int c = 0; c < cols; ++c) {
            dfs(0, c, pacific, heights);     
            dfs(rows - 1, c, atlantic, heights); 
        }

        for (int r = 0; r < rows; ++r) {
            dfs(r, 0, pacific, heights);      
            dfs(r, cols - 1, atlantic, heights);
        }

        std::vector<std::vector<int>> result;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};