class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) == m.end())
                m[nums[i]] = 1;
            else
                m[nums[i]] += 1;
        }
        for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
            if ((*it).second > nums.size()/2) return (*it).first;
        }
    }
};