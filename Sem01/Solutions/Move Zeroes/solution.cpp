class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0; 

        for (int read = 0; read < nums.size(); read++) {
            if (nums[read] != 0) {
                nums[write] = nums[read];
                write++;
            }
        }

        while (write < nums.size()) {
            nums[write] = 0;
            write++;
        }
    }
};
