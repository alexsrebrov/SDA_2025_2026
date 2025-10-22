#include <iostream>
#include <vector>
#include <algorithm>

int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), 
    [](std::vector<int> lhs, std::vector<int> rhs){
        return lhs[1] < rhs[1];
    });
    
    int cnt = 0;
    for(size_t i = 0, j = 1; i < intervals.size() && j < intervals.size();){
        if(intervals[i][1] > intervals[j][0]){
            cnt++;
            j++;
            continue;
        }
        i = j;
        j++;
    }
    return cnt;
}


int main(){
    std::vector<std::vector<int>> nums = {{1,2},{2,3},{3,4},{1,3}};

    std::cout<<eraseOverlapIntervals(nums);
}