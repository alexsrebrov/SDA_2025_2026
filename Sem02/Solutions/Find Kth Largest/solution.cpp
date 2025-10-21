class Solution {
private:
    int partitionDesc(vector<int>& a, int lo, int hi) {
        int pivot = a[(lo + hi) / 2];
        int i = lo, j = hi;

        while (true) {
            while (a[i] > pivot) i++;   // move right while > pivot
            while (a[j] < pivot) j--;   // move left  while < pivot
            if (i >= j) return j;
            swap(a[i], a[j]);
            i++; j--;
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0, end = nums.size() - 1;
        int target = k - 1; // 0-based index in descending order

        while (start < end) {
            int p = partitionDesc(nums, start, end);
            if (target <= p) {
                end = p;       // kth is in the left part [start..p]
            } else {
                start = p + 1; // kth is in the right part [p+1..end]
            }
        }
        return nums[start];
    }
};
