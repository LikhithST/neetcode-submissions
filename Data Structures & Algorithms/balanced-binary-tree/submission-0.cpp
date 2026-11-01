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
    
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0] == 1; //check if the isbalanced index is true
    }

private:
    vector<int> dfs(TreeNode* root){
        if (!root) {
            return {1, 0}; // base case, if recursion arrives at null pointer

            // 0th index represents if the tree is balanced and the 1st index represents the height of the tree
        }

        vector<int> left = dfs(root->left); // propagates all the left leaves until it encounters nullptr that is the end of the branch and comes back one step at a time with the {is_balanced, height}
        vector<int> right = dfs(root->right); // similarly with the right branch

        bool is_balanced = (left[0]==1 && right[0]==1 && (abs(left[1]-right[1]) <= 1)); // decides if the subtree of the just done recursion is balanced 

        int height = 1 + max(left[1], right[1]); // computes the height with the base case being height = 1 + 0 = 1

        return {is_balanced ? 1 : 0, height}; // returns arr of two elements representing is balanced and the height
    }
};
