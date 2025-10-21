class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;

        while (pos < n && nums[pos] < 0) pos++;

        int neg = pos - 1; 
        vector<int> res(n);

        while (neg >= 0 && pos < n) {
            int leftSq = nums[neg] * nums[neg];
            int rightSq = nums[pos] * nums[pos];

            if (leftSq <= rightSq) {
                res.push_back(leftSq);
                neg--;
            } else {
                res.push_back(rightSq);
                pos++;
            }
        }

        while (neg >= 0) {
            res.push_back(nums[neg] * nums[neg]);
            neg--;
        }

        while (pos < n) {
            res.push_back(nums[pos] * nums[pos]);
            pos++;
        }

        return res;
    }
};
