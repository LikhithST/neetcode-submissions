class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0; int n = nums.size();
        for (int i = 0 ; i < n ; i++){
            int cnt=0;
            for (int j = i ; j < n; j++){
                if (nums[j]==0) break;
                cnt++;
            }
            res = max(cnt,res);
        }
        return res;
    }

};