class Solution {
public:
    void dfs(
        vector<vector<int>>& graph,
        int target,
        vector<vector<int>>& allPaths,
        vector<int>& currentPath,
        int currentNode
    ) {
        currentPath.push_back(currentNode);

        if (currentNode == target) {
            allPaths.push_back(currentPath);
        }
        else {
            for (int& nextNode : graph[currentNode]) {
                dfs(graph, target, allPaths, currentPath, nextNode);
            }
        }

        currentPath.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;

        int source = 0;
        int target = graph.size() - 1;

        dfs(graph, target, allPaths, currentPath, source);

        return allPaths;
    }
};
