/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool operator<(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) return vector<Interval>();
        sort(intervals.begin(), intervals.end());
        vector<Interval> v;
        v.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= v[v.size()-1].end) {
                v[v.size()-1].end = v[v.size()-1].end > intervals[i].end ? v[v.size()-1].end : intervals[i].end;
            } else {
                v.push_back(intervals[i]);
            }
        }
        return v;
    }
};
