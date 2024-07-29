class Solution {
    vector<string> res;
    int m, n;

public:
    // Node struct for Trie
    struct trieNode {
        bool endWord;
        string word;
        trieNode* children[26];

        trieNode() : endWord(false), word("") {
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
    };

    // Get Trie Node
    trieNode* getNode() {
        return new trieNode();
    }

    // Insert word into Trie
    void insert(trieNode* root, const string& word) {
        trieNode* node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = getNode();
            }
            node = node->children[c - 'a'];
        }
        node->endWord = true;
        node->word = word;
    }

    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void findTrieWords(vector<vector<char>>& board, int i, int j, trieNode* root) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }

        if (board[i][j] == '$' || root->children[board[i][j] - 'a'] == nullptr) {
            return;
        }

        root = root->children[board[i][j] - 'a'];
        if (root->endWord) {
            res.push_back(root->word);
            root->endWord = false; // Avoid duplicates
        }

        char temp = board[i][j];
        board[i][j] = '$';

        for (const auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            findTrieWords(board, ni, nj, root);
        }

        board[i][j] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        trieNode* root = getNode(); // Create Trie
        for (const string& word : words) {
            insert(root, word);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (root->children[board[i][j] - 'a'] != nullptr) {
                    findTrieWords(board, i, j, root);
                }
            }
        }

        return res;
    }
};
