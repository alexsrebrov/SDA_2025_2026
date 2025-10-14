#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<std::pair<int,int>> ind_num(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        ind_num[i] = {i, nums[i]};
    }
    std::sort(ind_num.begin(), ind_num.end(), [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
        return a.second < b.second;
    });
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = ind_num[left].second + ind_num[right].second;
        if (sum == target) {
            return {ind_num[left].first, ind_num[right].first};
        } else if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }
    return {};
}

int main() {
    std::vector<int> nums = {3,2,4};
    int target = 6;
    std::vector<int> result = twoSum(nums, target);
    std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
    return 0;
}