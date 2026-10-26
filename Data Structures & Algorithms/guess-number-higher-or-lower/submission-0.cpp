/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        int mid, isGuess;
        while(low<=high){ // we iterate through all the elements in the range of n starting from 1
            mid = (low + high)/2; // step size of loop is log(n)
            isGuess = guess(mid);
            if(isGuess > 0){
                high = mid - 1; // if the guessed number num is greater than the actual number pick we bring the high pointer one less than the guessed number mid
            } else if (isGuess < 0){
                low = mid + 1; // if the guessed number num is less than the actual number pick we bring the low pointer one more than the guessed number mid
            } else {
                return mid; // if guess equal to zero our num that is mid is at the right number and we return the mid
            }
        }
    }
};