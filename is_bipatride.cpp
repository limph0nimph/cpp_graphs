class Solution {
public:

    bool dfs(int now, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& color) {
        visited[now] = true;
        for (auto el : graph[now]) {
            if (visited[el] && color[el] == color[now]) {
                return false;
            }
            if (!visited[el]) {
                color[el] = !color[now];
                if (!dfs(el, graph, visited, color)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<bool> color(graph.size(), false);
        for (size_t i = 0; i < visited.size(); ++i) {
            if (!visited[i]) {
                if (!dfs(i, graph, visited, color)) {
                    return false;
                }
            }
        }
        return true;
    }
