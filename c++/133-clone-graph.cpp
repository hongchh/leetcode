/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        allNode.clear();
        return recursiveClone(node);
    }
private:
    map<UndirectedGraphNode*, UndirectedGraphNode*> allNode;
    UndirectedGraphNode* recursiveClone(UndirectedGraphNode* node) {
        if (node == NULL) return NULL;
        if (allNode.find(node) != allNode.end())
            return allNode[node];
        UndirectedGraphNode* clone = new UndirectedGraphNode(node->label);
        allNode[node] = clone;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            (clone->neighbors).push_back(recursiveClone(node->neighbors[i]));
        }
        return clone;
    }
};