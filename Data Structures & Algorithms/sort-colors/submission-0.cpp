class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> counter(3, 0); // since the constraints in the problem mention that the numbers are in the range of 0 to 2

        for (const int& i : nums) {
            counter[i]++;
        }

        int i = 0; // to point the indices of the array to be returned
        for (int index = 0; index < counter.size(); index++){ // for the length of the counter
            for (int j=0; j<counter[index]; j++){ // write the index into the array to writer the value hold at the index
                nums[i] = index;
                i++;
            }
        }


    }
};