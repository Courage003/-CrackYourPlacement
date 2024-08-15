/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>res;
    vector<int> inorderTraversal(TreeNode* root) {
        /*if(root){
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;*/

        //Morris Inorder Traversal
        TreeNode *curr=root;
        while(curr){
            if(curr->left==NULL){
                res.push_back(curr->val);
                curr=curr->right;
            }

            else{
                TreeNode *leftChild=curr->left;
                while(leftChild->right!=NULL){
                    leftChild=leftChild->right;
                }

                leftChild->right=curr;

                //deleting previous links for prevent rewind
                TreeNode* temp=curr;
                curr=curr->left;
                temp->left=NULL;
            }
        }
        return res;
    }
};