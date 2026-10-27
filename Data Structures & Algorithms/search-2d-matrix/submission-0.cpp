class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int mid, q, r;
        int left = 0; 
        int right = m * n - 1; // converting 2d to 1d by doing this.

        while(left<=right){
            mid = left + (right - left) / 2;
            q = mid / n; // the mid index is at the qth row
            r = mid % n; // the mid index is at the rth column
            if (matrix[q][r] < target){
                left = mid + 1;
            } else if (matrix[q][r] > target) {
                right = mid - 1; 
            }
            else {
                return true;
            }
        }

        return false;

    }
};
