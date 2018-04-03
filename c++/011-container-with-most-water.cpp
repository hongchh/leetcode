class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size()-1;
        int _max = 0, area;
        while (low < high) {
            if (height[low] < height[high]) {
                area = height[low] * (high-low);
                ++low;
            } else {
                area = height[high] * (high-low);
                --high;
            }
            if (_max < area)
                _max = area;
        }
        return _max;
    }
};