class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> taskFrequency(26, 0);

        for (char task : tasks) {
            taskFrequency[task - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (int freq : taskFrequency) {
            if (freq > 0) {
                maxHeap.push(freq);
            }
        }

        int currentTime = 0;

        while (!maxHeap.empty()) {
            int cycleLength = n + 1;
            vector<int> tasksToReinsert;

            while (cycleLength > 0 && !maxHeap.empty()) {
                int remainingCount = maxHeap.top();
                maxHeap.pop();

                if (--remainingCount > 0) {
                    tasksToReinsert.push_back(remainingCount);
                }

                currentTime++; 
                cycleLength--;
            }

            for (int& count : tasksToReinsert) {
                maxHeap.push(count);
            }

            if (maxHeap.empty()) {
                break;
            }

            currentTime += cycleLength;
        }

        return currentTime;
    }
};
