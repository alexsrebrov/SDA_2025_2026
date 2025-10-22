#include <iostream>
#include <vector>
#include <algorithm>

bool containsDuplicate(std::vector<int>& nums){    
    if(nums.size() < 2) return false;

    sort(nums.begin(), nums.end());
    
    for(size_t i = 1; i < nums.size(); i++){
        if(nums[i] == nums[i-1]){
            return true;
        }
    }
    return false;        
}


int main(){
    std::vector<int> nums = {1,2,3,1};
    std::string s =(containsDuplicate(nums)? "true" : "false");
    std::cout<<s;
}