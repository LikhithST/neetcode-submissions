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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> kth_smallest = {0,0}; // 0th element represents counter to match with the k, and 1st element holds the val of the kth node
        find_kth_smallest(root, k, kth_smallest);
        return kth_smallest[1];
    }

private:
    void find_kth_smallest(TreeNode* root, int k, vector<int>& kth_smallest){
        if(!root){
            return; // return if reached the end of the tree
        }
        find_kth_smallest(root->left, k, kth_smallest); // first traverse to the left end of the tree. 
        kth_smallest[0]++; // start incrementing the kth element index in order 
        if(kth_smallest[0]==k){ // check if the kth indexed element is equal to the k input, if so assign the value 1st element of kth_smallest that was ment to hold the value of the kth_smallest element
            kth_smallest[1] = root->val;
        }
        find_kth_smallest(root->right, k, kth_smallest); // similary traverse the right subtree as the kth_smallest element can also be on the right subtree and also all the elements in the BST needs to be traversed
    }
};
