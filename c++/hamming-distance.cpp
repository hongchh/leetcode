class Solution {
public:
  int hammingDistance(int x, int y) {
    int count = 0;
    for (int i = x ^ y, j = 1, k = 0; k < 32; ++k) {
      if (i & (j << k)) {
        count += 1;
      }
    }
    return count;
  }
};