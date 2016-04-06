class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        deque<int> ans;
        ans.push_front(digits[digits.size()-1]+1);
        int carry;
        for (int i = digits.size()-2; i > -1; --i) {
            carry = ans[0]/10;
            ans[0] %= 10;
            ans.push_front(digits[i]+carry);
        }
        carry = ans[0]/10;
        ans[0] %= 10;
        if (carry != 0)
            ans.push_front(carry);
        return vector<int>(ans.begin(), ans.end());
    }
};