class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size(); int rightMax = -1; int currMax;

        for (int i = n-1; i >= 0 ; i--){
            if (arr[i]>=rightMax){
                currMax=arr[i];
            }
            arr[i]=rightMax;
            rightMax=currMax;
        }
        return arr;
    }
};