/*
 * 二分查找
 */

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size()-1;
        while (l <= r) {
        	int mid = (l+r)/2;
        	if (citations[mid-1] < citations.size()-mid+1 &&
        		citations[mid+1] >= citations.size()-mid-1 &&
        		citations[mid] >= citations.size()-mid) {
        		return citations.size()-mid;
        	} else if (citations[mid] >= citations.size()-mid) {
        		r = mid-1;
        	} else {
        		l = mid+1;
        	}
        }
        return 0;
    }
};