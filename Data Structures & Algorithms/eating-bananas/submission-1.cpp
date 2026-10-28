class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *std::max_element(piles.begin(), piles.end());
        int mid;
        int res;
        while(l<=r){ // we use binary search to find the integer in the range from 1..max(piles) to find the least k hours (here mid) to eat all piles within given time h

            mid = l + (r-l)/2;
            
            long long totalTime = 0;

            for (int i = 0 ; i < piles.size(); i++){
                totalTime += ceil(static_cast<double>(piles[i]) / mid); // adding the time taken at each pile for a k hours (mid here) per pile to see if total is less than or equal to the given h hours
            }

            if (totalTime <= h) { // we compare here the totaltime with h; if true we save the mid as the result but continue to test the lower ones in the 1..max(piles) range to find the lowest possible k (here mid) 
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};
