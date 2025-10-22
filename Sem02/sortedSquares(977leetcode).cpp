#include <iostream>
#include <vector>

std::vector<int> sortedSquares(std::vector<int>& nums) {
    std::vector<int> res(nums.size());
    int left = 0;
    int right = nums.size() - 1;
    int resIter = nums.size() - 1;
    while(left <= right){
        if(std::abs(nums[left]) >= std::abs(nums[right])){
            res[resIter--] = nums[left] * nums[left];
            left++;
            continue;
        }
        res[resIter--] = nums[right] * nums[right];
        right--;
    }

    return res;
}

int main(){
    std::vector<int> nums = {-4,-1,0,3,10};
    std::vector<int> res = sortedSquares(nums);

    for(size_t i = 0; i < res.size(); i++){
        std::cout<<res[i]<<" ";
    }
}
