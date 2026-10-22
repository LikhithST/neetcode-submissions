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
        if (e - s + 1 <= 1){
            return;
        }

        int m = (s + e)/2;
        mergeSortHelper(pairs, s, m);
        mergeSortHelper(pairs, m+1, e);
        merge(pairs, s, m, e);
    }

    void merge(vector<Pair>& arr, int s, int m, int e){
        vector<Pair> L(arr.begin() + s, arr.begin() + m + 1); // copying the left subarray
        vector<Pair> R(arr.begin() + m + 1, arr.begin() + e + 1); // copying the right subarray

        int i = 0, j = 0, k = s; // remember k should be index of array, that is s

        while(i < L.size() && j < R.size()){
            if (L[i].key <= R[j].key){
                arr[k] = L[i];
                ++i;
            }else{
                arr[k] = R[j];
                ++j;
            }
                ++k;
        }

        while( i < L.size()){
            arr[k] = L[i];
            ++k;
            ++i;
        }

        while( j > R.size()){
            arr[k] = R[j];
            ++k;
            ++j;
        }

    }
   
   };
