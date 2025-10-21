class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b){ return a[1] < b[1]; });
        // we should keep the first by earliest end
        int cnt = 0;                    
        int prevEnd = intervals[0][1];
        for (int i = 1; i < (int)intervals.size(); i++) {
            if (intervals[i][0] >= prevEnd) { // non-overlapping
                prevEnd = intervals[i][1];
            } else {
                cnt++;
            }
        }
        return cnt; // removals
    }
};
