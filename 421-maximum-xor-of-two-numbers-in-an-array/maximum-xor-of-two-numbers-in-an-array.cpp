class Solution {
public:
    struct trieNode {
        trieNode* left;  // 0
        trieNode* right; // 1

        trieNode() : left(nullptr), right(nullptr) {}
    };

    void insert(trieNode* root, int num) {
        trieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int i_b = (num >> i) & 1; // identify set bit or not
            if (i_b == 0) {
                if (!node->left) {
                    node->left = new trieNode();
                }
                node = node->left;
            } else {
                if (!node->right) {
                    node->right = new trieNode();
                }
                node = node->right;
            }
        }
    }

    int findXOR(trieNode* root, int num) {
        int maxXor = 0;
        trieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int i_b = (num >> i) & 1;
            if (i_b == 1) {
                if (node->left) {
                    maxXor |= (1 << i);
                    node = node->left;
                } else {
                    node = node->right;
                }
            } else {
                if (node->right) {
                    maxXor |= (1 << i);
                    node = node->right;
                } else {
                    node = node->left;
                }
            }
        }
        return maxXor;
    }

    int findMaximumXOR(vector<int>& nums) {
        trieNode* root = new trieNode();

        for (int num : nums) {
            insert(root, num);
        }

        int res = 0;
        for (int num : nums) {
            int temp = findXOR(root, num);
            res = max(res, temp);
        }

        return res;
    }
};
