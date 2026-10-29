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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val); // base case where root is a null pointer: this can help when the program reaches the end of the binary tree
        }

        if (val > root->val){
            root->right = insertIntoBST(root->right, val); // need to assign the returned new treenode to the right as the val of new node is greater than the root node
        }
        else {
            root->left = insertIntoBST(root->left, val);
            // need to assign the returned new treenode to the left as the val of new node is less than the root node
        }

        return root; // finally returns the root at the end of the recursion tree.

    }
};