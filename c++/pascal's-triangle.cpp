class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rows;
        for (int i = 0; i < numRows; ++i) {
            vector<int> ithRow;
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i)
                    ithRow.push_back(1);
                else
                    ithRow.push_back(rows[i-1][j-1]+rows[i-1][j]);
            }
            rows.push_back(ithRow);
        }
        return rows;
    }
};