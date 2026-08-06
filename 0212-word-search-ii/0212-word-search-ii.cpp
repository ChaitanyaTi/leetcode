#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    string word = "";
    int refCount = 0; // Number of words below this node
};

class Solution {
private:
    TrieNode* root;

    void insert(const string& word) {
        TrieNode* curr = root;
        curr->refCount++;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
            curr->refCount++;
        }
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* parent, vector<string>& result) {
        char ch = board[r][c];
        int idx = ch - 'a';
        TrieNode* curr = parent->children[idx];

        if (!curr || curr->refCount == 0) return;

        if (!curr->word.empty()) {
            result.push_back(curr->word);
            curr->word = ""; 
        }
        board[r][c] = '#';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] != '#') {
                if (curr->children[board[nr][nc] - 'a']) {
                    dfs(board, nr, nc, curr, result);
                }
            }
        }

        // Restore cell state
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (const string& w : words) {
            insert(w);
        }

        vector<string> result;
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (root->children[board[i][j] - 'a']) {
                    dfs(board, i, j, root, result);
                }
            }
        }

        return result;
    }
};