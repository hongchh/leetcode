class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1, 0);
        row[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == i)
                    row[j] = row[j-1];
                else if (j == 0)
                    continue;
                else
                    row[j] = row[j-1]+row[j];
            }
        }
        return row;
    }
};