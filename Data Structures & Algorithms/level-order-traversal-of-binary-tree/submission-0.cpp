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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q; // we are choosing queue because of FIFO nature of the datastructure, this helps in processing elements in the order root immediate children and then immediate children in iterative manner as required by a breadth first algorithm 
        vector<vector<int>> levelOrderList;
        q.push(root); // start with adding the root node to the queue
        while( q.size() > 0 ){
            vector<int>levelList;
            int q_size = q.size(); // store size in a value because in cpp it is continuosly evaluated at each iteration
            for (int i = 0; i < q_size; i++) { // the queue at the begining of the for loop at each level will only contain the elements of that level, but the elements being added inside the loop are not considered as the size is stored before the loop begun. the loop iteratively adds the elements of the next level while removing the elements of the current level (after storing the value in a levelList)
                TreeNode* cur = q.front(); // cpp way to access first element in the queue
                q.pop(); // pop should be done seperately
                if (cur!=nullptr){ // this is to check if we are not at the end of the tree and making not allowed operations
                q.push(cur->left);
                q.push(cur->right);
                levelList.push_back(cur->val);
                }
            }
            if (levelList.size() > 0){ // only append if there are any elements in levelList, this avoids the empty list in the last iteration on nullptr representing the end at the leaf nodes
            levelOrderList.push_back(levelList);
            levelList.clear(); // clear the levelList for the next level elements to be stored
            }
        }
        return levelOrderList;
    }
};
