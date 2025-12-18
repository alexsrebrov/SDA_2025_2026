class Solution {
public:

    struct Point {
        int dist;  
        int x;
        int y;

        Point(int d, int xx, int yy) : dist(d), x(xx), y(yy) {}
    };

    struct Compare {
        bool operator()(const Point& a, const Point& b) const {
            return a.dist < b.dist;  
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point, vector<Point>, Compare> maxHeap;

        for (auto& p : points) {
            int x = p[0];
            int y = p[1];
            int d = x*x + y*y;

            maxHeap.push({d, x, y});

            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        vector<vector<int>> result;

        while (!maxHeap.empty()) {
            auto p = maxHeap.top();
            maxHeap.pop();
            result.push_back({p.x, p.y});
        }

        return result;
    }
};
