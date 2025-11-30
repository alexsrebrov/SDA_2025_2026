class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;

        for(int& num : nums)
        {
            set.insert(num);
        }

        int longestSeq = 0;
        for(int& num : nums)
        {
            if(set.find(num - 1) == set.end())
            {
                int currLen = 1;
                int currNum = num;
                while(set.find(currNum + 1) != set.end())
                {
                    currLen++;
                    currNum++;
                }

                longestSeq = max(longestSeq, currLen);
            }
        }

        return longestSeq;
    }
};
