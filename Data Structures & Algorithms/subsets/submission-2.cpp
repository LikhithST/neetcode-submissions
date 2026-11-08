class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;  // vector to store the final subsets that are computed at the end
                                  // of reach bfs branch and is the result of this task
        vector<int> subset;  // a vector to keep track of all the subsets while propagating the tree

        dfs(nums, 0, subset, res);
        return res;
    }

    void dfs(const vector<int> nums, int i, vector<int>& subset, vector<vector<int>>& res) {
        if (i >= nums.size()) {  // if i = nums.size() it means that the tree has reached end and
                                 // the subset is added to the result
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);  //  interger from the nums array is a pushed and then dfs is
                                    //  called recursively
        dfs(nums, i + 1, subset, res);
        subset
            .pop_back();  // integer added before is removed and then again performs dfs recursively
        dfs(nums, i + 1, subset, res);
    }

    // this way both paths that is including a integer in nums and not including both the ways are
    // performed and the subsets resulted at the end of dfs are included to the result
};
