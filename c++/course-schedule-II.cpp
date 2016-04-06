class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> neighbors[numCourses];
        for (int i = 0; i < prerequisites.size(); ++i) {
            neighbors[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        int pre[numCourses] = {0};
        for (int i = 0; i < numCourses; ++i) {
            for (int j = 0; j < neighbors[i].size(); ++j)
                ++pre[neighbors[i][j]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (pre[i] == 0) q.push(i);
        }
        vector<int> topo;
        while (!q.empty()) {
            int v = q.front();
            topo.push_back(v);
            q.pop();
            for (int i = 0; i < neighbors[v].size(); ++i) {
                --pre[neighbors[v][i]];
                if (pre[neighbors[v][i]] == 0)
                    q.push(neighbors[v][i]);
            }
        }
        if (topo.size() == numCourses)
            return topo;
        return vector<int>();
    }
};