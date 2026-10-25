class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int m;
        while(l<=r){
            m = (l + r)/2; 
            if (nums[m] < target){
                l = m + 1; // if the mth element is less than the target in a sorted array, then the target value must be in the indices more than m, so we update the pointer to one greater than m
            }else if (nums[m] > target){
                r = m - 1; // if the mth element is greater than the target, then the target must be in the indices less than m, so we update the right pointer to one less than m
            }else{
                return m; // if the value at the mth indices is not less than or greater than m then it is the target and hence we return the indices
            }
        }
        return -1;
    }
};
