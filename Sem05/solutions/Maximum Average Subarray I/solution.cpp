class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int sum = 0;
        for(int i = 0;i < k; i++) {
            sum += nums[i];
        }
        double avg = (sum * 1.0) / k; 
        for(int i = k;i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            avg = max(avg, (sum * 1.0) / k);
        }
        return avg;
    }
};