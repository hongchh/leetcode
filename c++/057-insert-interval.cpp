/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ivec;
    	bool inserted = false;
    	for (int i = 0; i < intervals.size(); ++i) {
    		if (!inserted && intervals[i].start > newInterval.start) {
    			ivec.push_back(newInterval);
    			inserted = true;
    			--i;
    		} else {
    			ivec.push_back(intervals[i]);
    		}
    		checkIfMerge(ivec);
    	}
    	if (!inserted) {
    		ivec.push_back(newInterval);
    		checkIfMerge(ivec);
    	}
        return ivec;
    }
private:
	void checkIfMerge(vector<Interval>& v) {
		int s = v.size();
		if (s > 1 && v[s-1].start <= v[s-2].end) {
			v[s-2].end = v[s-1].end > v[s-2].end ? v[s-1].end : v[s-2].end;
			v.pop_back();
		}
	}
};