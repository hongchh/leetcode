class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int begin = 0;
    int end = numbers.size() - 1;
    while (numbers[begin] + numbers[end] != target) {
      if (numbers[begin] + numbers[end] > target) {
        --end;
      } else {
        ++begin;
      }
    }
    vector<int> ivec;
    ivec.push_back(begin + 1);
    ivec.push_back(end + 1);
    return ivec;
  }
};