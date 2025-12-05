class Solution {
public:
    int fib(int n) {
        vector<int> cache(n + 1, -1);
        
        return helper(n, cache);
    }

    int helper(int n, vector<int>& cache) {
        if(n == 0 || n == 1) return n;

        if(cache[n] != -1) return cache[n];

        return cache[n] = helper(n - 1, cache) + helper(n - 2, cache);
    }
};
