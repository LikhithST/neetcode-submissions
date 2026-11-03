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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        auto mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        vector<int> leftPre(preorder.begin()+1, preorder.begin() + mid + 1); // leftpre is elements from 1st index (as it is already put as the root node) to number of mid number of elements in the list 

        vector<int> rightPre(preorder.begin() + mid + 1, preorder.end()); // rightpre is the elements from mid+1 to end of preorder

        vector<int> leftIn(inorder.begin(), inorder.begin() + mid); // leftIn has elements from begin to the mid of inorder excluding the mid 

        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end()); // right in has elements from mid + 1 to end of inorder

        root->left = buildTree(leftPre, leftIn); // recursively call buildTree on left preorder and left inorder
        root->right = buildTree(rightPre, rightIn); // recursively call buildTree on right preorder and right inorder

        return root;
    }
};
