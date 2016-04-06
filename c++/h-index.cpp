class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h_index = 0;
        for (int i = citations.size()-1; i >= 0; --i) {
            if (citations[i] > h_index) {
                ++h_index;
            } else {
                break;
            }
        }
        return h_index;
    }
};