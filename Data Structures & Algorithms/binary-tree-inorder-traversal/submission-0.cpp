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
    vector<int> output;
    vector<int> inorderTraversal(TreeNode* root) {
      inorder(root); // call the inorder recursive in the inorderTraversal as it needs to return only the final output
      return output;
    }

private:
    void inorder(TreeNode* root){
        if (!root){
            return;
        }
        inorder(root->left); // first traverse left subtree until you reach the null
        output.push_back(root->val); // add the root val when the traversal of that subtree hits the nullptr
        inorder(root->right); // then traverse the right subtree similarly
    }

};