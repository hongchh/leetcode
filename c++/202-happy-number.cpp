class Solution {
public:
    bool isHappy(int n) {
        set<int> nums;
        while (1) {
            nums.insert(n);
            n = getNext(n);
            if (n == 1)
                return true;
            if (nums.find(n) != nums.end())
                return false;
        }
    }
private:
    int getNext(int n) {
        int temp = 0;
        while (n > 0) {
            int q = n%10;
            n /= 10;
            temp += q*q;
        }
        return temp;
    }
};