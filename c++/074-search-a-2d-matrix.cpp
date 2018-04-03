class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = findRow(matrix, target);
        if (row == -1) return false;
        int l = 0, r = matrix[row].size()-1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (matrix[row][mid] == target)
                return true;
            if (matrix[row][mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        return false;
    }
private:
    int findRow(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size()-1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (target >= matrix[mid][0] && target <= matrix[mid][matrix[mid].size()-1])
                return mid;
            if (target < matrix[mid][0])
                r = mid-1;
            else
                l = mid+1;
        }
        return -1;
    }
};