class Solution {
public:
  vector<int> constructRectangle(int area) {
    int factor = sqrt(area);
    while (area % factor > 0) {
      ++factor;
    }
    vector<int> ans;
    if (factor < area / factor) {
      ans.push_back(area / factor);
      ans.push_back(factor);
    } else {
      ans.push_back(factor);
      ans.push_back(area / factor);
    }
    return ans;
  }
};