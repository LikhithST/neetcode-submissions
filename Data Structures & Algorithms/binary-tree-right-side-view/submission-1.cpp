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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q; // we use queue datastructure because it suits the requirements of the breadth first search algorithm
        q.push(root); // we start with the root node
        vector<int>rightSideElements;
        while(q.size() > 0){ // we loop as long as there is element in the queue and the queue is added elements in the loop in the order of breadth first search
            int q_size = q.size(); // we save the size in the variable as while evaluation of condition in for loop we need the size of the queue at the begining of the loop. because inside for loop we add the left and right children of the nodes present in the queue at the begining of the for loop
            vector<int> levelList; // this is used to maintain elements in a particular level, and the for loop runs only for the elements belonging to a level
            for (int i = 0; i < q_size; i++){
                TreeNode* cur = q.front();
                q.pop();
                if (cur != nullptr){
                    q.push(cur->left); // left child node added to the queue to be processed in the next for loop representing the next level
                    q.push(cur->right); // similarly as above for right child node
                    levelList.push_back(cur->val); // adding all the elements belonging to the current level 
                }
            }
            if (!levelList.empty()){
    rightSideElements.push_back(levelList.back()); // only considering the last element of the vector as it represents the right most element of the level 
           // levelList.clear(); // clear the levelList for the next level to occupy , maybe this is not required as we are only interested in the last element 
            }
        }

        return rightSideElements; // return the list with all the right side visible nodes
    }
};
