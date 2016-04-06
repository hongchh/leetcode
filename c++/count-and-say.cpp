class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 1; i < n; ++i) {
            str = nextString(str);
        }
        return str;
    }
private:
    string nextString(string lastString) {
        lastString += ' ';
        int count = 1;
        char cur = lastString[0];
        string next = "";
        for (int i = 1; i < lastString.size(); ++i) {
            if (lastString[i] == cur) {
                ++count;
            } else {
                next += to_string(count);
                next += cur;
                cur = lastString[i];
                count = 1;
            }
        }
        return next;
    }
};