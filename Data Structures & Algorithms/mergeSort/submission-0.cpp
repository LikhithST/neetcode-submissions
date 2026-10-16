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
    vector<Pair> mergeSort(vector<Pair>& pairs) {
       // In case of recurrsion we always need to call the it as a function so we can recall it within the recursion function; a characteristic of recursion function is that it calls itself 

       mergeSortHelper(pairs, 0, pairs.size() - 1);
       return pairs;
    }
    void mergeSortHelper(vector<Pair>& pairs, int s, int e){
        if (s>=e){ // if the start is greater or equal to end then we have reached the end of recursion tree
            return;
        }

        // the middle is calculated this way so that it does not cause any -ve values or use int m = (s + e) / 2;
        int m = s + ( e - s ) / 2;

        mergeSortHelper(pairs, s, m);
        mergeSortHelper(pairs, m + 1, e);
        merge(pairs, s, m, e);

    } 

    void merge(vector<Pair>& pairs, int s, int m, int e){
        vector<Pair> L(pairs.begin() + s, pairs.begin() + m + 1);
        vector<Pair> R(pairs.begin() + m + 1, pairs.begin() + e + 1);

        int i = 0, j = 0, k = s;
        while(i < L.size() && j < R.size()){
            if(L[i].key <= R[j].key){
                pairs[k] = L[i];
                ++i;
            }
            else{
                pairs[k] = R[j];
                ++j;
            }
            ++k;
        }

        while (i < L.size()) {
            pairs[k] = L[i];
            ++i;
            ++k;
        }
        while (j < R.size()) {
            pairs[k] = R[j];
            ++j;
            ++k;
        }
    }

   };
