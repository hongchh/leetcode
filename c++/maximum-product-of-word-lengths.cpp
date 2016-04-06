class Solution {
public:
    int maxProduct(vector<string>& words) {
        markCharacter(words);
        int max = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i; j < words.size(); ++j) {
                if ((marks[i] & marks[j]) == 0) {
                    int product = words[i].size() * words[j].size();
                    max = max < product ? product : max;
                }
            }
        }
        delete [] marks;
        return max;
    }
private:
    int* marks;
    void markCharacter(vector<string>& words) {
        marks = new int[words.size()];
        for (int i = 0; i < words.size(); ++i) {
            int bitMark = 0;
            for (int j = 0; j < words[i].size(); ++j)
                bitMark |= (1 << (words[i][j]-'a'));
            marks[i] = bitMark;
        }
    }
};