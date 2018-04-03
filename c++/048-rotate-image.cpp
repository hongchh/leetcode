class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int l = (r-1)/2;
        for (int i = 0; i <= l; ++i) {
            for (int j = i; j < r-1-i; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[r-1-j][i];
                matrix[r-1-j][i] = matrix[r-1-i][r-1-j];
                matrix[r-1-i][r-1-j] = matrix[j][r-1-i];
                matrix[j][r-1-i] = temp;
            }
        }
    }
};