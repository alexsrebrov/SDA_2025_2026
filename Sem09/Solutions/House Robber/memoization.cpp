class Solution {
public:
    int helper(int i, vector<int>& nums, vector<int>& memo) {
        if (i < 0) return 0;
        if (i == 0) return nums[0];

        if (memo[i] != -1) return memo[i];

        int rob = nums[i] + helper(i - 2, nums, memo);
        int skip = helper(i - 1, nums, memo);

        return memo[i] = max(skip, rob);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> memo(n, -1);
        return helper(n - 1, nums, memo);
    }
};
