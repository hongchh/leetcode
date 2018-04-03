// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int mid = l+(r-l)/2;// 直接相加会溢出
            bool cur = isBadVersion(mid);
            bool pre = isBadVersion(mid-1);
            if (cur && !pre)
                return mid;
            else if (cur)
                r = mid-1;
            else
                l = mid+1;
        }
    }
};