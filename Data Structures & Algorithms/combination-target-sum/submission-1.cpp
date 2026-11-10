class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> current;
        backtrack(0, target, current, res, nums);
        return res;
    }

    void backtrack(int index, int remaining, vector<int>& current, 
                   vector<vector<int>>& res, const vector<int>& nums) {
        // Base case: combination found
        if (remaining == 0) {
            res.push_back(current);
            return;
        }

        // Base case: target exceeded or all elements considered
        if (remaining < 0 || index >= nums.size()) {
            return;
        }

        // Choice 1: Include nums[index] (can reuse the same element)
        current.push_back(nums[index]);
        backtrack(index, remaining - nums[index], current, res, nums);

        // Backtrack: Remove nums[index]
        current.pop_back();

        // Choice 2: Skip nums[index] and move to the next index
        backtrack(index + 1, remaining, current, res, nums);
    }
};
