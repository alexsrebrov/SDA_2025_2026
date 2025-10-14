#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
    int lastZeroIndex = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0) continue;
        std::swap(nums[i],nums[lastZeroIndex++]);
    }
}

int main()
{
    std::vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    for(int num : nums) {
        std::cout << num << " ";
    }
    return 0;
}


