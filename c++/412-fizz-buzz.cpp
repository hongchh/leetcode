class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> svec;
    for (int i = 1; i <= n; ++i) {
      if (i % 3 == 0 && i % 5 == 0) {
        svec.push_back("FizzBuzz");
      } else if (i % 3 == 0) {
        svec.push_back("Fizz");
      } else if (i % 5 == 0) {
        svec.push_back("Buzz");
      } else {
        svec.push_back(int2String(i));
      }
    }
    return svec;
  }
private:
  string int2String(int i) {
    string tmp = "";
    while (i > 0) {
      tmp += (i % 10 + '0');
      i /= 10;
    }
    string str = "";
    for (int j = tmp.size() - 1; j > -1; --j) {
      str += tmp[j];
    }
    return str;
  }
};