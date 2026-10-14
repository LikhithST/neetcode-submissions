// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> output;
        int j;
        
         for( int i = 0; i < pairs.size(); i++){ // the iteration starts from i = 1, because the first element is already sorted, but we can also start with 0 because we have a condition in the while loop j>=0; here we start from i = 0 to push the initial state of pairs to output
            j = i - 1;
            while( j>=0 && pairs[j+1].key < pairs[j].key ){
                Pair temp = pairs[j+1];
                pairs[j+1] = pairs[j];
                pairs[j] = temp;
                j=j-1;
            }
                output.push_back(pairs);
         }
         return output;
    }
};
