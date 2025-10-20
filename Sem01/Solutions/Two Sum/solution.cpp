#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> idx_num(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            idx_num[i] = {nums[i], i};
        }

        sort(idx_num.begin(), idx_num.end());

        int start = 0;
        int end = idx_num.size() - 1;

        while (start < end) {
            int sum = idx_num[start].first + idx_num[end].first;
            if (sum == target) {
                break;
            } else if (sum < target) {
                start++;
            } else {
                end--;
            }
        }

        return {idx_num[start].second, idx_num[end].second};    
    }
};
