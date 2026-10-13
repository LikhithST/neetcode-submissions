class Solution {
public:
    vector<int> cache; // initializing a vector to cache the computation in a recursive call. 
    int climbStairs(int n) {
        cache.resize(n,-1); // resize the vector to the size of steps i.e, n because we are only interested upto n steps and up to n steps is adding all possible ways of arriving at all the intermediate stairs steps.
        return dfs(n, 0);
    }

    int dfs(int n, int i) {
        if (i >= n) return i == n;
        if (cache[i]!=-1) return cache[i]; // check if the cache is modified with result and only then return
        cache[i] = dfs(n, i + 1) + dfs(n, i + 2); // cache the result of each step to use for recurring calls in other part of the decision tree.
        return cache[i];
    }
};