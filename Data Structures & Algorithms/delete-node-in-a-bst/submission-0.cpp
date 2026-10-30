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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return root;
        }

        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }else if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }else{
            if(!root->left) return root->right;
            if(!root->right) return root->left;

        TreeNode* curr = root->right; // because we always have greater numbers in the right subtree and the root node should be less than the right subtree, we find the least element in the right subtree and replace the root with it. 

        while(curr->left){
            curr = curr->left;
        }

        root->val = curr->val; // replace the root value with the curr value
        root->right = deleteNode(root->right, root->val);
    }
    return root;
    }
};