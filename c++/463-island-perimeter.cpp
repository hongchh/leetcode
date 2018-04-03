class Solution {
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int perimeter = 0;
    int row = grid.size();
    int col = grid[0].size();
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] == 1) {
          perimeter += 4;
          if (i - 1 > -1 && grid[i - 1][j] == 1) perimeter -= 1;
          if (i + 1 < row && grid[i + 1][j] == 1) perimeter -= 1;
          if (j - 1 > -1 && grid[i][j - 1] == 1) perimeter -= 1;
          if (j + 1 < col && grid[i][j + 1] == 1) perimeter -= 1;
        }
      }
    }
    return perimeter;
  }
};