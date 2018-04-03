class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int max = height[0], index = 0;
        for (int i = 1; i < height.size(); ++i) {
            if (max < height[i]) {
                max = height[i];
                index = i;
            }
        }
        int water = 0, h = height[0];
        for (int i = 0; i < index; ++i) {
            if (h > height[i]) {
                water += h-height[i];
            } else {
                h = height[i];
            }
        }
        h = height[height.size()-1];
        for (int i = height.size()-1; i > index; --i) {
            if (h > height[i]) {
                water += h-height[i];
            } else {
                h = height[i];
            }
        }
        return water;
    }
};