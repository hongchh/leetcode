// 时间/空间复杂度 O(N)
// 利用桶排，将nums数据装到bucketNum个桶里面
// 相邻非空的桶之间的差值就是可能的maxGap

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int maxVal = nums[0];
        int minVal = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > maxVal) maxVal = nums[i];
            if (nums[i] < minVal) minVal = nums[i];
        }

        int bucketGap = ceil((double)(maxVal-minVal)/(nums.size()-1));
        bucketGap = (bucketGap < 1 ? 1 : bucketGap);
        int bucketNum = (maxVal-minVal)/bucketGap + 1;
        vector<bucketRecord> bucket(bucketNum);

        for (int i = 0; i < nums.size(); ++i) {
            int pos = (nums[i]-minVal)/bucketGap;
            bucket[pos].isEmpty = false;
            if (nums[i] > bucket[pos].max)
                bucket[pos].max = nums[i];
            if (nums[i] < bucket[pos].min)
                bucket[pos].min = nums[i];
        }

        int maxGap = 0, lastBucketMax = minVal;
        for (int i = 0; i < bucketNum; ++i) {
            if (!bucket[i].isEmpty) {
                int gap = bucket[i].min-lastBucketMax;
                if (gap > maxGap) maxGap = gap;
                lastBucketMax = bucket[i].max;
            }
        }
        return maxGap;
    }
private:
    struct bucketRecord {
        int max;
        int min;
        bool isEmpty;
        bucketRecord() {
            this->max = -1;
            this->min = 2147483647;
            isEmpty = true;
        }
    };
};