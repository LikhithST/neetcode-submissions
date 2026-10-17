class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1Copy(nums1.begin(), nums1.begin() + m); // copy the valid elements nums1 
        int i = 0, j = 0, k = 0; // pointers to iterate over indices of nums1copy, nums2 and nums1 respectively


        while(k < m + n){
            if (j>=n || (i < m && nums1Copy[i] <= nums2[j])){ // if j >= n that means no elements left in nums2 to compare, if i < m that means no more elements in nums1Copy
                nums1[k++] = nums1Copy[i++];
            }else{
                nums1[k++] = nums2[j++];
            }
        }
        


    }

  
};