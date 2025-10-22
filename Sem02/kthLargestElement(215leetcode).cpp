#include <iostream>
#include <vector>

int findKthLargest(std::vector<int>& nums, int k) {
    int max = nums[0];
    int min = nums[0];
    int res = 0;
    for(size_t i = 0; i < nums.size(); i++){
        if(min > nums[i]) min = nums[i];
        if(max < nums[i]) max = nums[i];
    }

    int range = max - min + 1;
    int* counter = new int[range] {0};

    for(size_t i = 0; i < nums.size(); i++){
        counter[nums[i] - min]++;
    }


    for(int i = range - 1; i >= 0; i--){
            k-=counter[i];
            if(k <= 0){ 
            res = i + min;
            break;
        }
    }
    delete[] counter;
    return res;
}

int main(){
    std::vector<int> nums= {3,2,3,1,2,4,5,5,6};
    int k = 4;

    std::cout<<findKthLargest(nums,k);
}