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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root){ // return false if the root does not exist
            return false;
        }
        int sum = root->val; // start with the root node value as the sum as it will be useful when we backpropagate in recursion and we won't end up subtracting the root node which will cause some errors
        return pathSumHelper(root, targetSum, sum); // recursive function that returns a boolean value
    }

    bool pathSumHelper(TreeNode* root, int targetSum, int& sum){
    if (root->left == nullptr && root->right == nullptr){
        return targetSum == sum; // check and return a bool val if we have reached the leaf node
    }

    if (root->left != nullptr){ // if the left node is present add it to the sum and check
        sum = sum + root->left->val;
       bool didTargetReach = pathSumHelper(root->left, targetSum, sum);
        if(didTargetReach){
            return true; // if the left branch returns with target reached as true return true
        } else {
            sum = sum - root->left->val; // if not backpropagation we subtract the val of left node that we added, Remember: we will not return here as the right subtree is not yet explored
        }
    }
    if (root->right != nullptr){ // if there is a right node we add the value of the right node and check if the target sum reached
        sum = sum + root->right->val; 
        bool didTargetReach = pathSumHelper(root->right, targetSum, sum);
        if(didTargetReach){
            return true; // if reached we return true 
        } else {
            sum = sum - root->right->val; // if not returned we subtract the value of the right node that we added in this recursive func context
            // return false; // here notice we return false, it can also be skipped as we have a return at the end of the recursive func to catch all
        }
    }
        return false;
}
};